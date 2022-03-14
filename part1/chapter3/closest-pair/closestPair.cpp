//created by gravitorious

#include <bits/stdc++.h>

using namespace std;


vector<pair<int, int>> newVector(vector<pair<int, int>> a, int start, int end){
	
	vector<pair<int, int>> result;
	for(long long i = start; i <= end; i++){
		result.push_back(a[i]);
	}
	return result;
}



double disPoints(pair<int, int> p1, pair<int, int> p2){
	return sqrt(((p1.first - p2.first) * (p1.first - p2.first)) + 
				((p1.second - p2.second) * (p1.second - p2.second)));
	
}


pair<pair<int, int>, pair<int, int>> closestSplitPair(vector<pair<int, int>> Px, vector<pair<int, int>> Py, pair<int, int> medianPair, double d){
	
	vector<pair<int, int>> Sy;
	
	for(auto &x : Py){
		if((x.first > (medianPair.first - d)) && (x.first < (medianPair.first + d))){
			Sy.push_back(x);
		}
	}
	double best = d;
	pair<pair<int, int>, pair<int, int>> bestPair; //it may be empty
	bool flag = false;
	for(int i = 0; i < (int) Sy.size() - 1; i++){
		for(int j = 0; j < min(7, (int) Sy.size()-i-1); j++){
			double dis = disPoints(Sy[i], Sy[i+j+1]);
			if(dis < best){
				best = dis;
				bestPair.first = Sy[i];
				bestPair.second = Sy[i+j+1];
				flag = true;
			}
		}
	}
	if(flag == false){
		bestPair.first = make_pair(-1, -1);
		bestPair.second = make_pair(-1, -1);
	}
	
	return bestPair;
}


pair<pair<int, int>, pair<int, int>> closestPair(vector<pair<int, int>> Px, 
												 vector<pair<int, int>> Py){
					
	
	pair<pair<int, int>, pair<int, int>> pd;
	if(Px.size() < 2) return pd;
	else if(Px.size() == 2){
		pd.first = Px[0];
		pd.second = Px[1];
		return pd;
	}
	else if(Px.size() == 3){
		double d1 = disPoints(Px[0], Px[1]);
		double d2 = disPoints(Px[0], Px[2]);
		double d3 = disPoints(Px[1], Px[2]);
		double min;
		if(d1 <= d2){
			min = d1;
			pd.first = Px[0];
			pd.second = Px[1];
		}
		else{
			min = d1;
			pd.first = Px[0];
			pd.second = Px[2];
		}
		if(d3 < min){
			min = d3;
			pd.first = Px[1];
			pd.second = Px[2];
		}
		return pd;
	}
	int firstHalfSize = ceil(Px.size() / 2.0);
	int  secondHalfSize = floor(Px.size() / 2.0);
	vector<pair<int, int>> Lx = newVector(Px, 0, firstHalfSize - 1);
	vector<pair<int, int>> Rx = newVector(Px, firstHalfSize, firstHalfSize + secondHalfSize - 1);
	pair<int, int> medianPoint = Px[ceil(Px.size() / 2.0) - 1];
	vector<pair<int, int>> Ly, Ry;
	for(auto &x : Py){
		if(x.first <= medianPoint.first) Ly.push_back(x);
		else Ry.push_back(x);
	}
	pair<pair<int, int>, pair<int, int>> leftBestPair= closestPair(Lx, Ly);
	pair<pair<int, int>, pair<int, int>> rightBestPair = closestPair(Rx, Ry);
	double leftBestDistance = disPoints(leftBestPair.first, leftBestPair.second);
	double rightBestDistance = disPoints(rightBestPair.first, rightBestPair.second);
	double d = min(leftBestDistance, rightBestDistance);
	pair<pair<int, int>, pair<int, int>> splitBestPair = closestSplitPair(Px, Py, medianPoint, d);
	if(leftBestDistance < rightBestDistance) pd = leftBestPair;
		else pd = rightBestPair;
	if(splitBestPair.first.first == -1){
		return pd;
	}
	return splitBestPair;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int, int>> points;
	vector<pair<int, int>> Px;
	vector<pair<int, int>> Py;
	int n, x, y;
	
	cin >> n; //number of points
	for(int i = 0; i < n; i++){
		cin >> x;
		cin >> y;
		points.push_back(make_pair(x, y));
	}
	
	Px = points;
	std::sort(Px.begin(), Px.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});
	Py = points;
	std::sort(Px.begin(), Px.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});
	
	
	
	pair<pair<int, int>, pair<int, int>> pd;
	pd = closestPair(Px, Py);
	cout << "Smallest distance: " << disPoints(pd.first, pd.second) << "\n";
	cout << "From the points : (" << pd.first.first << "," << pd.first.second
							<<") (" <<  pd.second.first << "," << pd.second.second
							<<")\n"; 
	
	
	
}
