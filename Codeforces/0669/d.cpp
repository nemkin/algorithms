#include <iostream>
using namespace std;
int main() {
	int n, q;
	cin>>n>>q;
	int shifts[2];
	int start = 0;
	shifts[0] = 0;
	shifts[1] = 0;
	
	int op;
	int shift;
	
	for(int i=0; i<q; ++i) {
		cin>>op;
		switch(op) {
			case 1:
				cin>>shift;
				shifts[start] += shift/2;
				shifts[(start+1)%2] += shift/2;
				cout<<shift<<' '<<(shift%2)<<endl;	
				if((shift%2)!=0) {
					shifts[(start+1)%2] += (0<shift) ? 1 : -1;
					start = (start+1)%2;
				}
			break;
			case 2:
				start = (start+1)%2;	
			break;
		}
	}
	cout<<start<<' '<<shifts[0]<<' '<<shifts[1]<<endl;
	if(start == 0) {

		for(int i=1; i<=n; ++i) {
			int ptln, prs;
			//Ptln
				ptln = (n+(i+shifts[0]-1)%n)+1;
				++i;	
			//Prs
				prs = (n+(i+shifts[1]-1)%n)+1;

			cout<<ptln<<' '<<prs<<' ';
		}


	} else {
		for(int i=1; i<=n; ++i) {
			int ptln, prs;
			//Ptln
				ptln = ((i+shifts[1]-1)%n)+1;
				while(ptln<=0) ptln+=n;	
				++i;	
			//Prs
				prs = ((i+shifts[0]-1)%n)+1;
				while(prs<=0) prs+=n;

			cout<<prs<<' '<<ptln<<' ';

		}
	
	}


	return 0;
}
