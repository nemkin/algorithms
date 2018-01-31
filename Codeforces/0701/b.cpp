#include <iostream>
using namespace std;

bool cols[100000];
bool rows[100000];

int main () {
	int n, m;
	cin>>n>>m;

	long long numofrows = n;
	long long numofcols = n;

	int crow, ccol;

	for(int i=0; i<m; ++i) {
		cin>>crow>>ccol;
		crow--; ccol--;
		
		if(!rows[crow]) {
			--numofrows;
			rows[crow] = true;
		}

		if(!cols[ccol]) {
			--numofcols;
			cols[ccol] = true;
		}

		cout<<numofrows*numofcols<<' ';
	}

	cout<<endl;

	return 0;	
}
