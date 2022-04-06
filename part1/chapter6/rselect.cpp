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
	for(int j = l+1; j < r+1; j++){
		if(A[j] < p){
			swap(A[j], A[i]);
			i++;
		}
	}
	swap(A[l], A[i-1]);
	return i-1; //return final pivot position
}

int chooseRandomPivot(vector<int> &A, int l, int r){
	return myUniRand(l, r);
}


int rselect(vector<int> &A, int l, int r, int searchp){
	if(l>=r) return A[l];
	int i = chooseRandomPivot(A, l, r);
	swap(A[l], A[i]);
	int j = partition(A, l, r);
	if(j == searchp) return A[j];
	else if(j > searchp) return rselect(A, l, j-1, searchp);
	else return rselect(A, j+1, r, searchp);

}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int> A;
	while(cin >> n){
		A.push_back(n);
	}
	int position = 50; //put the ith position of the smallest element you want to find.
		
	int element = rselect(A, 0, A.size()-1, position-1);
	cout << "The element in the position " << position << " is: " << element << "\n";
	
}
