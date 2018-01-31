#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin>>n>>m;

	vector<int> edges[n];
	vector<int> order;
	
	order.resize(m);

	long long pages[n];
	long long optpages[n];

	for(int i=0; i<n; ++i) {
		pages[i] = 0;
		optpages[i] = 0;
	}
	
	int a,b;
	cin>>a;
	order[0]=a-1;
    

    bool readedge = false;
	for(int i=1; i<m; ++i) {
		cin>>b;
		
		if(a!=b) {
            readedge = true;
            edges[a-1].push_back(b-1);
		    edges[b-1].push_back(a-1);
		}

		order[i] = b-1;

		a=b;
	}

    if(!readedge) {
        cout<<0<<endl;
        return 0;
    }

	for(int i=0; i<n; ++i) if(!edges[i].empty()) sort(edges[i].begin(), edges[i].end());

	for(int i=0; i<n; ++i) if(!edges[i].empty()) {

		for(int j=0; j<edges[i].size(); ++j) {
			
			pages[i] += abs(i-edges[i][j]);

		}

		int imod = edges[i][edges[i].size()/2];

		for(int j=0; j<edges[i].size(); ++j) {
			
			optpages[i] += abs(imod-edges[i][j]);

		}		
	}

	int maxopt = 0;
	int maxopti = 0;

	for(int i=0; i<n; ++i) if(!edges[i].empty()) {
		
		if(maxopt < pages[i]-optpages[i]) {
			maxopt = pages[i]-optpages[i];
			maxopti = i;
		}
		
	}


	long long sumpages = 0;

	for(int i=0; i<m; ++i) {
		if(order[i] == maxopti) order[i] = edges[maxopti][edges[maxopti].size()/2];
	}
 
	for(int i=1; i<m; ++i) {
		sumpages+=abs(order[i]-order[i-1]);
	}
	
	cout<<sumpages<<endl;	

	return 0;
}
