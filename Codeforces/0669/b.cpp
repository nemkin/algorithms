#include <iostream>
using namespace std;
int main () {
	int n;
	cin>>n;
	
	char dir[n];
	int l[n];

	for(int i=0; i<n; ++i) cin>>dir[i];
	for(int i=0; i<n; ++i) cin>>l[i];
	
	int curr = 0;
	int nc;

	for(int i=1; i<=n+3; ++i) {
		if(dir[curr]=='>')  {
			nc = curr+l[curr];
		} else {
			nc = curr-l[curr];
		}
		if(!(0<=nc && nc<n)) {
			cout<<"FINITE"<<endl;
			return 0;
		}
		curr = nc;
	}
        cout<<"INFINITE"<<endl;	
	return 0;
}
