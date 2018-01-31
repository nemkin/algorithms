#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
using namespace std;

//Max num of vertices.
#define N 202

//Edmonds-Karp algorithm.
struct MaxFlowMinCut {

	//Set by hand before calling init().

	//Actual num of vertices
	int n;

	//Original directed capacity matrix.
	int co[N][N];

	//Source
	int s;

	//Target
	int t;


	//Set by init().

	//Current directed capacity matrix.
	int cc[N][N];

	//Current flow
	int f[N][N];

	//Max flow found.
	int maxflow;

	//Set by BFS().

	//Parent table
	int p[N];

	//Flow on the path
	int flow;

	void init() {

		maxflow = 0;

		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
			cc[i][j] = co[i][j];
			f[i][j] = 0;
		}		
	}

	void calculate() {

		while(BFS()) {
			
			cout<<endl<<endl<<"Search graph:"<<endl;
			for(int i=0; i<n; ++i) {
				for(int j=0; j<n; ++j) {
					cout<<cc[i][j]<<' ';
				}
				cout<<endl;
			}
			cout<<endl;

	

			cout<<endl<<endl<<"Before:"<<endl;
			for(int i=0; i<n; ++i) {
				for(int j=0; j<n; ++j) {
					cout<<f[i][j]<<' ';
				}
				cout<<endl;
			}
			cout<<endl;

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
			
			cout<<"After:"<<endl;
			for(int i=0; i<n; ++i) {
				for(int j=0; j<n; ++j) {
					cout<<f[i][j]<<' ';
				}
				cout<<endl;
			}
			cout<<endl<<endl;

		}
		//In p[N] now anybody whose parent is not -1 is in the cut part of the graph.
		//Anybody whose p[i] is not -1 AND is not listed as a parent is on the edge of the cut.
	}


	bool BFS() {

		int m[n];

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

set<int> primes;

int main() {

	int n;
	cin>>n;

	int fox[n];

	for(int i=0; i<n; ++i) cin>>fox[i];

	for(int i=2; i<20000; ++i) {
		bool prime = true;
		for(int j=2; j<=sqrt(i); ++j) {
			if((i%j) == 0) {
				prime = false;
				break;
			}
		}
		if(prime) {
			primes.insert(i);
		}
	}

	MaxFlowMinCut mfmc;

	mfmc.s = n;
	mfmc.t = n+1;
	mfmc.n = n+2;	

	for(int i=0; i<mfmc.n; ++i) for(int j=0; j<mfmc.n; ++j) mfmc.co[i][j] = 0; 

	for(int i=0; i<n; ++i) {
		if((fox[i])%2) { //ptln
			mfmc.co[mfmc.s][i] = 2;
		} else { //prs
			mfmc.co[i][mfmc.t] = 2;
		}
	}

	for(int i=0; i<n; ++i) for(int j=0; j<i; ++j) {
		if(primes.find(fox[i]+fox[j]) != primes.end() ) {
			if((fox[i])%2) {
				mfmc.co[i][j] = 1;
			} else {	
				mfmc.co[j][i] = 1;
			}
		}
	}	

	mfmc.init();
	mfmc.calculate();
	
	
	cout<<mfmc.maxflow<<endl;
	cout<<endl;
	for(int i=0; i<mfmc.n; ++i) {
		for(int j=0; j<mfmc.n; ++j) {
			cout<<mfmc.co[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<mfmc.n; ++i) {
		for(int j=0; j<mfmc.n; ++j) {
			cout<<mfmc.f[i][j]<<' ';
		}
		cout<<endl;
	}

	if(mfmc.maxflow!=n) {
		cout<<"Impossible"<<endl;
		return 0;
	}


	int comp[n];
	for(int i=0; i<n; ++i) comp[i] = 0;
	
	int curr = 0;
	comp[curr] = 1;

	while(true) {
		bool found = false;
		for(int i=0; i<n; ++i) {
			if(mfmc.f[curr][i] || mfmc.f[i][curr]) {
				mfmc.f[curr][i] = 0;
				mfmc.f[i][curr] = 0;
				comp[i] = comp[curr];
				curr = i;
				found=true;
				break;
			}
		}
		if(!found) {
			for(curr=0; curr<n; ++curr) if(!(comp[curr])) break;
			if(curr==n) break;
		}
	}
	
	for(int i=0; i<n; ++i) cout<<comp[i]<<' ';
	cout<<endl;

	return 0;
}
