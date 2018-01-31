#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct {
	int p;
	int c;
} pc;
bool cmp (pc a, pc b) {
	if(a.p<b.p) return true;
	if(a.p == b.p  && a.c<b.c) return true;
	return false;
}
int main() {
	int n;
	cin>>n;
	if(n==1) {
		cout<<"1.0"<<endl;
		return 0;
	}
	
	pc pca[n-1];
	int cc[n] = {0};
	for(int i=1; i<n; ++i) {
		cin>>pca[i-1].p;
		--pca[i-1].p;
		pca[i-1].c=i;
		++cc[pca[i-1].p];
	}
	sort(pca, pca+n-1, cmp);
	
	int adj[n][2];	

	for(int i=0; i<n; ++i) {
		adj[i][0] = adj[i][1] = -1;
	}
	
	adj[0][0] = 0;
	adj[pca[n-2].p][1] = n-2;
	
	for(int i=1; i<n-1; ++i) {
		if(pca[i-1].p!=pca[i].p) {
			adj[pca[i-1].p][1] = i-1;
			adj[pca[i].p][0] = i;
		}
	}
	
	for(int i=0; i<n-1; ++i) {
		cout<<pca[i].p<<' '<<pca[i].c<<endl;
	}
	cout<<"--"<<endl;
	for(int i=0; i<n; ++i) {
		cout<<cc[i]<<endl;	
	}
	cout<<"---"<<endl;
	for(int i=0; i<n; ++i) {
		cout<<adj[i][0]<<' '<<adj[i][1]<<endl;
	}
	cout<<"---"<<endl;
	int tt2[n] = {0};
	tt2[0] = 2;
	
	queue<int> frontier;
	frontier.push(0);
	int curr;
	while(!frontier.empty()) {
		curr = frontier.front(); frontier.pop();
		if(adj[curr][0] == -1) continue;
		int subcurr;
		for(int i=adj[curr][0]; i<=adj[curr][1]; ++i) {
			subcurr = pca[i].c;
			tt2[subcurr] = tt2[curr]+cc[curr]+1;
			frontier.push(subcurr);	
		}

	}
		
	for(int i=0; i<n; ++i) {
		cout<<tt2[i]<<endl;
	}
	return 0;

}
