//created by gravitorious
//quicksort with distinct elements

#include <bits/stdc++.h>

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int myUniRand(int a, int b){
	//a to b
	uniform_int_distribution<int> distribution(a,b);
	return distribution(rng);
}

int partition(vector<int> &A, int l, int r){
	int p = A[l];
	int i = l+1;
	cout << " einai l kai r: " << l << " " << r << "\n";
	for(int j = l+1; j < r+1; j++){
		if(A[j] < p){
			swap(A[j], A[i]);
			i++;
		}
	}
	swap(A[l], A[i-1]);
	return i-1; //return final pivot position
}

//returns the position of first element
int choosePivotFL(vector<int> &A, int l, int r){
	return l;
}

//returns the position of last element
int choosePivotLL(vector<int> &A, int l, int r){
	return r;
}

int chooseRandomPivot(vector<int> &A, int l, int r){
	return myUniRand(l, r);
}

int chooseMedianOfThree(vector<int> &A, int l, int r){
	int m = (l+r)/2;
	if(A[l] > A[r]){
		if(A[l] < A[m]){
			return l;
		}
		else{
			if(A[r] > A[m]) return r;
			else return m;
		}
	}
	else{
		if(A[m] > A[r]){ return r;}
		else{
			if(A[l] > A[m]) return l;
			else return m;
		}
	}
}

void quicksort(vector<int> &A, int l, int r, int *comparisons){
	if(l>=r) return;
	//int i = choosePivotFL(A, l, r);
	//int i = choosePivotLL(A, l ,r);
	//int i = chooseRandomPivot(A, l, r);
	int i = chooseMedianOfThree(A, l, r);
	swap(A[l], A[i]);
	int j = partition(A, l, r);
	for(auto &x : A){
		cout << x << "\n";
	}
	cout << "pivot position " << j << "\n";
	quicksort(A, l, j-1, comparisons);
	quicksort(A, j+1, r, comparisons);
	*comparisons = *comparisons + (r-l);

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int> A;
	while(cin >> n){
		A.push_back(n);
	}
	int comparisons = 0;
	
	quicksort(A, 0, A.size()-1, &comparisons);
	
	cout << "Sorted array" << "\n";
	for(auto &x : A){
		cout << x << "\n";
	}
	cout << "Comparisons: " << comparisons << "\n";
	
}
