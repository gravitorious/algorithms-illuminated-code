//created by gravitorious

#include <bits/stdc++.h>
const int INF = 1e9; // 10^9 = 1B < 2^31 - 1

using namespace std;



double disPoints(pair<int, int> p1, pair<int, int> p2){
	return sqrt(((p1.first - p2.first) * (p1.first - p2.first)) + 
				((p1.second - p2.second) * (p1.second - p2.second)));
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int, int>> points;
	pair<pair<int, int>, pair<int, int>> pd;
	double min =INF;
	int n, x, y;
	
	cin >> n; //number of points
	for(int i = 0; i < n; i++){
		cin >> x;
		cin >> y;
		points.push_back(make_pair(x, y));
	}
	
	
	double d;
	for(int i = 0; i < (int) points.size(); i++){
		for(int j = i + 1; j < (int) points.size(); j++){
			d = disPoints(points[i], points[j]);
			if(d < min){
				min = d;
				pd.first = points[i];
				pd.second = points[j];
			}
		}
	}
	
	
	cout << "Smallest distance: " << min << "\n";
	cout << "From the points : (" << pd.first.first << "," << pd.first.second
							<<") (" <<  pd.second.first << "," << pd.second.second
							<<")\n"; 
	
	
	
}
