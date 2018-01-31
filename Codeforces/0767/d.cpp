#include <iostream>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

int fm[10000001];
int sm[10000001];

typedef struct {
	int i;
	int e;
} ie;

ie indexexpire[10000001];

bool cmp (ie a, ie b) {
	if(a.e<b.e) return true;
	return false;
}

int main() {

	int n; //num in fridge
	int m; //num in shop
	int k; //num daily

	cin>>n>>m>>k;

	int mday = 0;
	int e;
	for(int i=0; i<n; ++i) {
		cin>>e;
		if(mday<e) mday=e;
		++fm[e];
	}

	for(int i=0; i<m; ++i) {
		cin>>e;
		if(mday<e) mday=e;
		++sm[e];
		indexexpire[i].i=i+1;
		indexexpire[i].e=e;
	}

	int fdb=0, sdb=0;

	sort(indexexpire, indexexpire+m, cmp);

	for(int i=mday; 0<=i; --i) {
		fdb+=fm[i];
		sdb+=sm[i];

		if(k<=fdb) {
			fdb-=k;
		} else {
			sdb-=(k-fdb);
			fdb=0;
			if(sdb<0) sdb=0;
		}
	}

	if(0<fdb) {
		cout<<"-1"<<endl;
		return 0;
	}

	int buy=m-sdb;

	cout<<buy<<endl;

	for(int i=m-1; m-1-buy<i; --i) {
		cout<<indexexpire[i].i<<' ';	
	}

	return 0;
}
