#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define N 500

using namespace std;

struct MaxMatchBipartiteGraph {
	//Set by caller.
	vector<int> adj[N];

	//Used by DFS.
	bool visited[N];

	//Return
	int match[N];

	MaxMatchBipartiteGraph() {
		memset(match, -1, sizeof match);
	}

	//Augmenting path.
	bool DFS(int from) {
		if(visited[from]) return false;
		visited[from] = true;

		for(auto& u: adj[from]) {

			if(match[u] == -1 || DFS(match[u])) {
					match[from] = u;
					match[u] = from;
					return true;
			}		

		}
		return false;
	}

	void solve () {
		for(int i=0; i<N; ++i) if(match[i] == -1) {
			memset(visited, false, sizeof visited);
			DFS(i);
		}

	}
	
};

int toMins (string time) {
	int hours, mins;

	hours = (time[0]-'0')*10 + time[1]-'0';
	mins = (time[3]-'0')*10 + time[4]-'0';

	return hours*60 + mins;
}

bool canDo (int wmb, int wme, int jmb, int jme) {
	if(wmb<=jmb && jme<=wme) return true;
	return false;
}

int main () {
	int currentTask, numOfTasks;
	int numw, numj;

	cin>>numOfTasks;

	for(currentTask = 0; currentTask<numOfTasks; ++currentTask) {
		cin>>numw>>numj;
		string tmp;
		int minw[numw][2], minj[numj][2];

		for(int i=0; i<numw; ++i) {
			cin>>tmp;
			minw[i][0] = toMins(tmp);
			cin>>tmp;
			minw[i][1] = toMins(tmp);
		}

		for(int i=0; i<numj; ++i) {
			cin>>tmp;
			minj[i][0] = toMins(tmp);
			cin>>tmp;
			minj[i][1] = toMins(tmp);
		}

		MaxMatchBipartiteGraph mmbp;

		//Generating graph
		for(int i=0; i<numw; ++i) for (int j=0; j<numj; ++j) {
			if(canDo(minw[i][0], minw[i][1], minj[j][0], minj[j][1])) {
				mmbp.adj[i].push_back(numw+j);
				mmbp.adj[numw+j].push_back(i);
			}
		}

		mmbp.solve();
		int match = 0;
		for(int i=0; i<numw; ++i) if(mmbp.match[i]!=-1) ++match;
		cout<<match<<endl;	
	}
	return 0;
}
