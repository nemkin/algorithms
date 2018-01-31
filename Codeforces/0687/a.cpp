#include <iostream>
#include <algorithm>

using namespace std;

bool cmp (int a[2], int b[2]) {
	if(a[0] < b[0]) return true;
	if(a[0] == b[0] && a[1] < b[1]) return true;
	return false;
}

int main() {
	int n, m;
	cin>>n>>m;

	int group[n] = {0};
	int edges[2*m][2];

	for(int i=0; i<2*m; ++i) {
		cin>>edges[i][0]>>edges[i][1];
		edges[m+i][0] = edges[i][1];
		edges[m+i][1] = edges[i][0];
	}
	
	sort(edges, edges+2*m, cmp);
	
	for(int i=0; i<n; ++i) {
		if(group[i]!=0) continue;
				

	}
	
	return 0;
}
