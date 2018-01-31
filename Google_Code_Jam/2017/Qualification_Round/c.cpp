#include <iostream>
#include <cmath>
using namespace std;
int main() {
	
	int t;
	cin>>t;
	for(int c=1; c<=t; ++c) {
		long long n,k;
		cin>>n>>k;
			
		long long leftpart, rightpart;

		for(;0<k; k=k>>1) {
			
			leftpart = (n-1)/2;
			rightpart = (n-1)/2 + (n-1)%2;
			
			if(k==1) break;

			if(k%2) {
				n=leftpart;
			} else {
				n=rightpart;
			}
		}
		
		cout<<"Case #"<<c<<": "<<max(leftpart,rightpart)<<' '<<min(leftpart,rightpart)<<endl;	
	}
	
	return 0;
}
