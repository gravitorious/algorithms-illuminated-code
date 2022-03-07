//created by gravitorious

#include <bits/stdc++.h>

using namespace std;

//recursive algorithm to find the second largest number of array with integers
//where array length is a power of 2 and all numbers are distinct.
//We know that the largest number will be compared with the second largest
//number among the tree. For each number, we will store all numbers
//that are smaller than this number. In the end, the largest number will 
//contain a list with log2(n) size, so we will need log2(n)-1 comparisons
//to find the second largest number. As a result we will have n+log2(n)-2 comparisons.
//(we are not counting the base comparison).

map<int, vector<int>> numbersmap;

int largestNumber(int v[], int l_bound, int u_bound){
	
	//base comparison
	if(u_bound - l_bound == 0){
		return v[l_bound];
	}
	
	int v_size = u_bound - l_bound + 1;
	int s1 = largestNumber(v, l_bound, l_bound + (v_size/2)-1);
	int s2 = largestNumber(v, l_bound + (v_size/2), u_bound);
	
	if (s1 <= s2){
		numbersmap[s2].push_back(s1);
		return s2;
	}
	else {
		numbersmap[s1].push_back(s2);
		return s1;
	}
}


//log2(n) - 1 comparisons

int returnSecondLargestNumber(int largestNumber){
	int max = numbersmap[largestNumber][0];
	for(int i = 1; i < (int) numbersmap[largestNumber].size(); i++){
		if(max < numbersmap[largestNumber][i]){
			max = numbersmap[largestNumber][i];
		}
	}
	return max;
	
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	int v[8] = {900,3,-2,5,15,6,7,-10};
	int s = largestNumber(v, 0, 7);
	int secondLargestNumber = returnSecondLargestNumber(s);
	cout << "The second largest number is: " << secondLargestNumber << "\n";
	
}
