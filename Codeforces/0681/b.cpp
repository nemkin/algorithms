#include <iostream>
#include <cmath>
using namespace std;
int main () { 
	long long a,b,c,n;
	cin>>n;
	long long cmax = n*9/10000;
	long long u;
	long long l;
	for(c=0; c<=cmax; ++c) {
		l = n - 1234*c;
		for(u=35273*l/123456; u<=352732*l/1234567; ++u) {
			if(u==925) {
				cout<<u<<' '<<l<<endl;
			}
		}
	}
	return 0;
}
