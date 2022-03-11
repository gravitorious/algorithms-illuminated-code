//created by gravitorious

#include <bits/stdc++.h>
/*
 * Recursive algorithm to count inversions on array. 
 * O(nlogn)
 * We have modified the mergesort algorithm from the previous chapter.
 * To test our algorithm we have used the <<Challenge data set>> from the
 * author site https://www.algorithmsilluminated.org/
 * */

using namespace std;

vector<long long> newVector(vector<long long> a, long long start, long long end){
	
	vector<long long> result;
	for(long long i = start; i <= end; i++){
		result.push_back(a[i]);
	}
	return result;
}

//merge two arrays
vector<long long> mergeAndCountSplitInv(vector<long long> &a, vector<long long> &b, long long *splitInv){
	
	vector<long long> mergedResult;
	long long ai = 0;
	long long bi = 0;
	
	for(long long i = 0; i < (long long) a.size() + (long long) b.size(); i++){
		if(ai == (long long) a.size()){
			mergedResult.push_back(b[bi]);
			bi++;
			continue;
		}
		if(bi == (long long) b.size()){
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
			(*splitInv) = (*splitInv) + ceil((((long long) a.size() + (long long) b.size())/2.0)) - ai;
		}
	}	
	
	return mergedResult;
}


vector<long long> sortAndCountInversions(vector<long long> a, long long *inv){
	
	if((long long)a.size() == 1 || (long long)a.size() == 0){
		return a; 
	}
	long long size = (long long) a.size() - 1;
	vector<long long> firstHalf = newVector(a, 0, (size/2));
	vector<long long> secondHalf = newVector(a, (size/2)+1, size);

	long long leftInv = 0;
	vector<long long> C = sortAndCountInversions(firstHalf, &leftInv);
	long long rightInv = 0;
	vector<long long> D = sortAndCountInversions(secondHalf, &rightInv);
	long long splitInv = 0;
	vector<long long> B = mergeAndCountSplitInv(C, D, &splitInv);
	
	(*inv) = leftInv + rightInv + splitInv;
	return B;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long number;
	vector<long long> a;
	while(cin >> number){
		a.push_back(number);
	}
	long long inv = 0;
	vector<long long> result = sortAndCountInversions(a, &inv);
	cout << "The number of Inversions are: " << inv << "\n";
	
}
