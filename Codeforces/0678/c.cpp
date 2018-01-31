#include <iostream>
#include <cmath>
using namespace std;
long long lcm (long long a, long long b, long long stop) {
	long long ares = a;
	long long bres = b;
	while(ares!=bres && ares<=stop && bres<=stop) {
		if(ares<bres) ares+=a;
		else bres+=b;
	}
	return max(ares,bres);
}

int main() {

	long long n,a,b,apay,bpay;
	cin>>n>>a>>b>>apay>>bpay;
	
	long long adivcount = n/a;
	long long bdivcount = n/b;

	if(apay<bpay) adivcount -= n/lcm(a,b,n);
	else bdivcount -= n/lcm(a,b,n);
	
	cout<<adivcount*apay+bdivcount*bpay<<endl;
		
	return 0;
}
