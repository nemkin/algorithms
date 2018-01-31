#include <iostream>
using namespace std;
int main () {
	int n;
	int a;
	cin>>n>>a;
	int crim[n];
	
	for(int i=0; i<n; ++i) cin>>crim[i];

	int firstsym, lastsym;
	int cached = 0;

	if (2*a-1<n) {
		firstsym = 0;
		lastsym = 2*a-2;
	} else if (2*a-1 == n) {
		firstsym = 0;
		lastsym = n-1;
	} else {
		firstsym = (2*a-1)-n;
		lastsym = n-1;
	}
	
	for(int i=0; i<n; ++i) {
		if(i<firstsym || lastsym<i) cached+=crim[i];
	}

	cached+=crim[a-1];

	
	while(firstsym!=lastsym) {
	if(crim[firstsym] == 1 && crim[lastsym] == 1) cached+=2;
	
	firstsym++;
	lastsym--;
	}
	cout<<cached<<endl;	
	return 0;
}
