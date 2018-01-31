#include <iostream>
#include <vector>
using namespace std;

#define N 100

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


int main() {
	

	return 0;
}
