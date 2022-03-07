//created by gravitorious

#include <bits/stdc++.h>

using namespace std;

//recursive algorithm to find the largest number of array with integers
//when the array has length in power of two
//n-1 comparisons

int largestNumber(int v[], int l_bound, int u_bound){
		
	if(u_bound - l_bound == 0){
		return v[l_bound];
	}
	
	
	int v_size = u_bound - l_bound + 1;
	int s1 = largestNumber(v, l_bound, l_bound + (v_size/2)-1);
	int s2 = largestNumber(v, l_bound + (v_size/2), u_bound);
	
	if (s1 <= s2) return s2;
	else return s1;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	int v[8] = {17,3,-2,13,7,6,4,116};
	int s = largestNumber(v, 0, 7);
	cout << "The largest number is: " << s << endl;
	
}
