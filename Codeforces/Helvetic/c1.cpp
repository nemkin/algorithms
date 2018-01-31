#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
	int from, to;
} edge;

bool cmp (edge a, edge b) {
	if(a.from<b.from) return true;
	if(a.from == b.from && a.to < b.to) return true;
	return false;
}
int main() {
	int n, m;
	cin>>n>>m;

	edge edges[2*m];

	for(int i=0; i<2*m; ++i) {
		cin>>edges[i].from>>edges[i].to;
		edges[m+i].to = edges[i].from;
		edges[m+i].from = edges[i].to;
	}

	if(n!=(m+1)) {
		cout<<"no"<<endl;
		return 0;
	}

	sort(edges, edges+2*m, cmp);

	int edgelist[n][2];

	edgelist[0][0] = 0;
	edgelist[n-1][1] = 2*m-1;

	for(int i=1; i<2*m; ++i) {
		if(edges[i-1].from != edges[i].from) {
			edgelist[edges[i-1].from][1] = i-1;
			edgelist[edges[i].from][0] = i;
		}
	}

	for(int i=0; i<2*m; ++i) {
		cout<<edges[i].from<<' '<<edges[i].to<<endl;
	}

	for(int i=0; i<n; ++i) {
		cout<<edgelist[i][0]<<' '<<edgelist[i][1]<<endl;
	}

	bool visited[n] = {false};
	bool fronted[n] = {false};
	queue<int> frontier;
	frontier.push(0);
	fronted[0] = true;

	int curr;
	while(!frontier.empty()) {
		curr = frontier.front(); frontier.pop();
		visited[curr] = true;

		for(int i=edgelist[curr][0]; i<=edgelist[curr][1]; ++i) {
			if(!visited[edges[i].to] && !fronted[edges[i].to]) {
				frontier.push(edges[i].to);
				fronted[edges[i].to] = true;
			}
		}
	}	
	

	for(int i=0; i<n; ++i) {
		if(!visited[i]) {
			cout<<"no"<<endl;
			return 0;
		}
	}

	cout<<"yes"<<endl;
	return 0;
}
