#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef struct {
	int f, t;
} edge;

bool cmp (edge a, edge b) {
	if(a.f<b.f) return true;
	if(a.f == b.f && a.t<b.t) return true;
	return false;
}

int main () {
	int n, m;
	cin>>n>>m;

	edge edges[2*m];

	int tmpf, tmpt;

	int original[n];

	for(int i=0; i<n; ++i) {cin>>original[i];}

	for(int i=0; i<m; ++i) {
		cin>>tmpf>>tmpt;
		tmpf--;
		tmpt--;

		edges[i].f = tmpf;
		edges[i].t = tmpt;
		edges[m+i].f = tmpt;
		edges[m+i].t = tmpf;
	}
	sort(edges, edges+2*m, cmp);

	int adj[n][2];
	adj[0][0] = 0;
	adj[n-1][1] = 2*m-1;

	for(int i=1; i<2*m; ++i) {
		if(edges[i-1].f != edges[i].f) {
			adj[edges[i-1].f][1] = i-1;
			adj[edges[i].f][0] = i;
		}	
	}

	set<int> tobedone;

	for(int i=0; i<n; ++i) tobedone.insert(i);

	set<int>::iterator it = tobedone.begin();

	while(it != tobedone.end()) {

			// BFS ----------------
			bool visited[n] = {false};
			set<int> visitset;
			queue<int> frontier;

			int curr;
			frontier.push(*it);
			visited[*it] = true;
			visitset.insert(*it);
			while(!frontier.empty()) {
				curr = frontier.front(); frontier.pop();
				for(int i=adj[curr][0]; i<=adj[curr][1]; ++i) {
					if(!visited[edges[i].t]) {
						visited[edges[i].t] = true;
						visitset.insert(edges[i].t);
						tobedone.erase(edges[i].t);
						frontier.push(edges[i].t);
					}

				}

			}

			//EOFBFS ------------


			//Reorder visited;
			vector<int> reorder;
			for(int i : visitset) {
				reorder.push_back(original[i]);
			}

			sort(reorder.begin(), reorder.end(), std::greater<int>());

			int rindex = 0;
			for(int i : visitset) {
				original[i] = reorder[rindex++];	
			}

		++it;	
		
	}

	for(int i=0; i<n; ++i) cout<<original[i]<<' ';
	cout<<endl;

	return 0;
}
