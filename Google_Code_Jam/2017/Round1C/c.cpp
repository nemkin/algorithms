#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
	
	int t;
	cin>>t;
	cout<<setprecision(20)<<scientific;
	for(int c=1; c<=t; ++c) {

		int n,k; cin>>n>>k;
		double u; cin>>u;
		
		double p[n+1]; for(int i=0; i<n; ++i) cin>>p[i];
		p[n] = 1;
		++n;
	
		sort(p,p+n);


		for(int i=0; i<n-1; ++i) if(u>0) {
			double diff = (p[i+1]-p[i]);
			if(diff*(i+1) <= u) {
				
				for(int j=0; j<=i; ++j) {
					p[j] = p[i+1];
				}

				u-=diff*(i+1);
			}
			else {
				for(int j=0; j<=i; ++j) {
					p[j] += u/(double)(i+1);
				}
				break;
			}
		
		}
	
		double result =1;
		for(int i=0; i<n; ++i) result*=p[i];

		cout<<"Case #"<<c<<": "<<result<<endl;
	}
	

	return 0;
}
