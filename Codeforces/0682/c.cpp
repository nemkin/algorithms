#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int p[100000];
long long edgeweight[100000];
long long vertexmaxweight[100000];
vector<long long> edgelist[100000];
bool toCut[100000];

void DFS(long long maxweightsofar, int vertex) {
	if(maxweightsofar>vertexmaxweight[vertex]) {
		toCut[vertex] = true;
		return;
	}
	
	int currvertex;
	for(int i=0; i<edgelist[vertex].size(); ++i) {
		currvertex = edgelist[vertex][i];
		DFS(max(maxweightsofar+edgeweight[currvertex], edgeweight[currvertex]),currvertex); 		
	}	
}

int reached;
void reach(int vertex) {
        if(toCut[vertex]) return;
	++reached;
	int currvertex;
	for(int i=0; i<edgelist[vertex].size(); ++i) {
		currvertex = edgelist[vertex][i];
		reach(currvertex); 		
	}	
}

int main() {

	cin>>n;
	for(int i=0; i<n; ++i) cin>>vertexmaxweight[i];
	for(int i=1; i<n; ++i) {
		cin>>p[i];
		cin>>edgeweight[i];
		p[i]--;
	}
	p[0]=-1;
	edgeweight[0]=0;	

	for(int i=1; i<n; ++i) {
		edgelist[p[i]].push_back(i);
	}
	
	DFS(0,0);
	reach(0);
	
	cout<<n-reached<<endl;
	
	return 0;
}

