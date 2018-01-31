#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

//Max num of vertices.
#define N 200

//Edmonds-Karp algorithm.
struct MaxFlowMinCut {

//Set by hand before calling init().
	
	//Actual num of vertices
	int n;
	
	//Original directed capacity matrix.
	long int co[N][N];

	//Source
	int s;

	//Target
	int t;


//Set by init().
	
	//Current directed capacity matrix.
	long int cc[N][N];

	//Current flow
	long int f[N][N];

	//Max flow found.
	long int maxflow;

//Set by BFS().

	//Parent table
	int p[N];
	
	//Flow on the path
	long int flow;

	void init() {

		maxflow = 0;

		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
			cc[i][j] = co[i][j];
			f[i][j] = 0;
		}		

	}

	void calculate() {
		
		while(BFS()) {
			maxflow +=flow;
			int curr = t;
			int par;
			while(curr!=s) {
				par = p[curr];
				cc[par][curr] = cc[par][curr] - flow;
				cc[curr][par] = cc[curr][par] + flow;
	
				f[par][curr] = f[par][curr] + flow;

				curr = par;
			}
		}
		//In p[N] now anybody whose parent is not -1 is in the cut part of the graph.
		//Anybody whose p[i] is not -1 AND is not listed as a parent is on the edge of the cut.

	}


	bool BFS() {

		long int m[n];

		for(int i=0; i<n; ++i) {
			p[i] = -1;
			m[i] = 0;
		}

		m[s] = -2;
		p[s] = -2;

		queue<int> frontier;

		frontier.push(s);

		while(!frontier.empty()) {

			int curr = frontier.front();
			frontier.pop();

			for(int i=0; i<n; ++i) if(cc[curr][i]>0 && p[i] == -1) {
				
				p[i] = curr;
				m[i] = (m[curr] == -2) ?  cc[curr][i] : min(cc[curr][i], m[curr]);
				
				if(i==t) {
					flow = m[t];
					return true;
				} else {
					frontier.push(i);	
				}
			}

		}
		flow=0;
		return false;
	}

};

MaxFlowMinCut mfmc;

int main () {
	int m;
	cin>>m;
	
	mfmc.n = N;
	mfmc.s = 'A';
	mfmc.t = 'Z';
	
	char fromc, toc;
	int from, to;
	long int weight;
	
	for(int i=0; i<mfmc.n; ++i) for(int j=0; j<mfmc.n; ++j) {
		mfmc.co[i][j] = 0;
	}
	
	for(int i=0; i<m; ++i) {
		cin>>fromc>>toc>>weight;
		from = (int)fromc;
		to = (int)toc;
		mfmc.co[from][to] += weight;
		mfmc.co[to][from] += weight;
	}
	
	
	mfmc.init();
	mfmc.calculate();
	cout<<mfmc.maxflow<<endl;
	

	return 0;
}
