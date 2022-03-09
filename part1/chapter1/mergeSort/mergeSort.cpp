//created by gravitorious

#include <bits/stdc++.h>

using namespace std;

vector<int> newVector(vector<int> a, int start, int end){
	
	vector<int> result;
	for(int i = start; i <= end; i++){
		result.push_back(a[i]);
	}
	return result;
}

//merge two arrays
vector<int> mergeTwoArrays(vector<int> &a, vector<int> &b){
	
	vector<int> mergedResult;
	int ai = 0;
	int bi = 0;
	
	for(int i = 0; i < (int) a.size() + (int) b.size(); i++){
		if(ai == (int) a.size()){
			mergedResult.push_back(b[bi]);
			bi++;
			continue;
		}
		if(bi == (int) b.size()){
			mergedResult.push_back(a[ai]);
			ai++;
			continue;
		}
		
		if(a[ai] <= b[bi]){
			mergedResult.push_back(a[ai]);
			ai++;
		}
		else{
			mergedResult.push_back(b[bi]);
			bi++;
		}
	}	
	
	return mergedResult;
}


vector<int> mergeSort(vector<int> a){
	
	if((int)a.size() == 1 || (int)a.size() == 0){
		return a; 
	}
	int size = (int) a.size() - 1;
	vector<int> firstHalf = newVector(a, 0, (size/2));
	vector<int> secondHalf = newVector(a, (size/2)+1, size);

	vector<int> C = mergeSort(firstHalf);
	vector<int> D = mergeSort(secondHalf);
	
	return mergeTwoArrays(C, D);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, number;
	vector<int> a;
	
	cin >> n; //size of first array
	for(int i = 0; i < n; i++){
		cin >> number;
		a.push_back(number);
	}
	
	vector<int> result = mergeSort(a);
	cout << "sorted array with mergesort: " << "\n";
	for(auto &x : result) cout << x << "\n";
}
