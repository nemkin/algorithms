#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

int n;
vector<int> nbs[1000008];
queue<int> q, dq;
vector<int> t, dt;
vector<int> divs;
vector<int> numnbs;
vector<int> dnumnbs;
vector<int> volt;
vector<int> dvolt;


int main() {
	
	scanf("%d", &n);
	t.resize(n+8);
	dt.resize(n+8);
	dnumnbs.resize(n+8);
	numnbs.resize(n+8);
	volt.resize(n+8);
	dvolt.resize(n+8);
	int a,b;
	for (int i = 0; i < n-1; i++){
		scanf("%d %d", &a, &b);
		nbs[a].push_back(b);
		nbs[b].push_back(a);
	}
	
	for (int i = 1; i <= n ; i++){
		dnumnbs[i] = nbs[i].size();
		dvolt[i] = -1;
	}
	
	
	
	// divisors
	for (int i = 2; i < sqrt(n); i++){
		if (n%i == 0) {
			divs.push_back(i);
			divs.push_back(n/i);
		}
	}
	if (n == int(sqrt(n)) * int(sqrt(n)))
		divs.push_back(int(sqrt(n)));
	
	for (int i = 1; i <= n ; i++){
		dt[i] = -1;
	}
	
	/*for (int i = 1; i <= n; i++){
		cout<<i<<" "<<dnumnbs[i]<<" "<<nbs[i].size()<<endl;
	}*/
	
	
	// default q
	for (int i = 1; i <= n; i++){
		if (dnumnbs[i] == 1) {
			//dq.push(i);
			//dt[ i ] = 0;
			dt[nbs[i][0]] += 1;
			nbs[ nbs[i][0] ].erase(  find(nbs[nbs[i][0]].begin(), nbs[nbs[i][0]].end(), i )  );
			//cout<<i<<" leaf"<<endl;
		}
	}
	for (int i = 1; i <= n; i++){
		if (dt[i] != -1)  {
			dt[i] += 2;
			if (nbs[i].size() == 1)
				dq.push(i);
		}
	}
	
	/*for (int i = 1; i <= n; i++){
		if (dnumnbs[i] == 1) {
			dt[i] = 0;
		}
	}*/
	
	/*for (int i = 1; i < n; i++){
		cout<<i;
		for (int j : nbs[i]) {
			cout<<" "<<j;
		}
		cout<<endl;
	}
	
	for (int i = 1; i <= n; i++){
		cout<<dt[i]<<" ";
	}
	cout<<endl;*/
	
	
	
	
	
	
	vector<int> oks;
	oks.push_back(n-1);
	for (int K : divs) {
		//cout<<"\n K:"<<K<<endl;
		//if (K==1)
		//	continue;
		
		q = dq;
		t = dt;
		numnbs = dnumnbs;
		volt = dvolt;
		
		//cout<<"q size: "<<q.size()<<endl;
		
		bool ok = true;
		while (!q.empty()) {
			int c = q.front();
			//cout<<"Current: "<<c<<endl;
			volt[c] = 1;
			q.pop();
			if (t[c] == -1)
				t[c] = 1;
			//t[c] = 1;
			for (int i : nbs[c]) {
				numnbs[i]--;
				if (volt[i] == -1) {
					//cout<<c<<" nb: "<<i<<" "<<numnbs[i]<<endl;
					if (numnbs[i] == 1) {
						q.push(i);
					}
				}
				else
					t[c] += t[i];
			}
			/*cout<<"t: ";
			for (int j = 1; j <= n; j++) {
				cout<<t[j]<<" ";
			}
			cout<<endl;*/
			
			if (t[c] == K)
				t[c] = 0;
			if (t[c] > K) {
				ok = false;
				break;
			}
			
			
			
		}
		if (ok) {
			oks.push_back(n/K - 1);
			//oks.push_back(K);
		}
	}
	
	
	sort(oks.begin(), oks.end());
	
	for (unsigned i = 0; i < oks.size(); i++){
		if (i>0) cout<<" ";
		cout<<oks[i];
	}
	
	cout<<endl;
	
	
	
	
	return 0;
}
