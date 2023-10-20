#include <iostream>
#include <cmath>
using namespace std;

long long mod_fact (long long num, long long mod) {
	long long fact = 1;
	
	for (long long i=2; i<=num; ++i) {
		
		if(i == mod) {	
			continue;
		}
		
		fact = (fact*i)%mod;
	}
	
	return fact;
}

long long mod_pow (long long num, long long pow, long long mod) {
	
		long long res = 1;
		long long sq = num%mod;
		
		for (long long bit = 0; (1<<bit) <= pow; ++bit) {
			
			if((1<<bit) & pow) {
				res *= sq;
				res = res%mod;
			}
			
			sq = sq*sq%mod;
		}
		
		return res;
}

int main() {
	
	long long n,p,r;
	cin>>n>>p>>r;

	if (n==2) {
		
		if (r==1) cout<<"2 1"<<endl;
		else cout<<"-1 -1"<<endl;
		
		return 0;
	}
	
	if (n>= 2*p) {
		
		if(r==0) {
			cout<<"2 1"<<endl;
			return 0;
		}
		
		else {
			
			cout<<"-1 -1"<<endl;
			return 0;
			
		}	
	}
	
	if(n>=p) {
		
		if(r==0) {
			for(long long k=2; k<=n; ++k) {
				if(k!=p) {
					cout<<k<<" "<<1<<endl;
					return 0;
				}
			}
		}
		
		else {
			long long nmod = mod_fact(n,p);
			
			long long c = (r*mod_pow(nmod, p-2, p)) % p;
			
			if (1<=c) {
				cout<<p<<" "<<c<<endl;
				return 0;
			} else {
				cout<<"-1 -1"<<endl;
				return 0;
			}
		}
		
	}

	if(n<p) {
		if (r==0) {
			cout<<"-1 -1"<<endl;
			return 0;
		}
		
		else {
			
			long long nmod = mod_fact(n,p);
			long long rights = (r*mod_pow(nmod, p-2, p))%p;
			
			for(long long k=2; k<=n; ++k) {
				
				long long v = (k*rights)%p;
				
				if(1<=v && v<k) {
					cout<<k<<" "<<v<<endl;
					return 0;
				}
			}
		}
	}
	
	cout<<"-1 -1"<<endl;
	return 0;
}
