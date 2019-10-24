#include <bits/stdc++.h> 
#include <boost/functional/hash.hpp> 

using namespace std; 


int maxPointOnSameLine(vector< pair<int, int> > points) 
{ 
	int N = points.size(); 
	if (N < 2) 
		return N; 

	int maxPoint = 0; 
	int curMax, overlapPoints, verticalPoints; 
	unordered_map<pair<int, int>, int,boost:: 
			hash<pair<int, int> > > slopeMap; 

	for (int i = 0; i < N; i++) 
	{ 
		curMax = overlapPoints = verticalPoints = 0; 


		for (int j = i + 1; j < N; j++) 
		{ 
			if (points[i] == points[j]) 
				overlapPoints++; 
			else if (points[i].first == points[j].first) 
				verticalPoints++; 

			else
			{ 
				int yDif = points[j].second - points[i].second; 
				int xDif = points[j].first - points[i].first; 
				int g = __gcd(xDif, yDif); 


				yDif /= g; 
				xDif /= g; 
				slopeMap[make_pair(yDif, xDif)]++; 
				curMax = max(curMax, slopeMap[make_pair(yDif, xDif)]); 
			} 

			curMax = max(curMax, verticalPoints); 
		} 


		maxPoint = max(maxPoint, curMax + overlapPoints + 1); 
		slopeMap.clear(); 
	} 

	return maxPoint; 
} 


int main() 
{ 
	const int N = 6; 
	int arr[N][2] = {{-1, 1}, {0, 0}, {1, 1}, {2, 2}, 
					{3, 3}, {3, 4}}; 

	vector< pair<int, int> > points; 
	for (int i = 0; i < N; i++) 
		points.push_back(make_pair(arr[i][0], arr[i][1])); 

	cout << maxPointOnSameLine(points) << endl; 

	return 0; 
} 
