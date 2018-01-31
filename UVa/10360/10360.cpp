#include <iostream>
#include <map>
#include <utility>

using namespace std;

int dp[2][1025];

int main() {

	int n, d;
	cin>>d>>n;
	map<pair<int,int>, int> ratmap;

	int x,y,pop;

	for(int i=0; i<n; ++i) {
		cin>>x>>y>>pop; --x; --y;
		ratmap.insert(make_pair(make_pair(x,y), pop));
	}

	int max = 0, maxx = 0, maxy = 0;	

	for(int i=0; i<=2*d; ++i) for(int j=0; j<=2*d; ++j) {
		auto p = make_pair(i,j);
		if(ratmap.find(p) != ratmap.end()) dp[d%2][d] += ratmap[p];
	}
	cout<<dp[d%2][d]<<endl;
	
	for(int i=d; i<=1024-d; ++i) for(int j=d+1; j<=1024-d; ++j) {
		
	}
	

	return 0;
}
