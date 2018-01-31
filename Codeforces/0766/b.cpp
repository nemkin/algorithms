#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int n;
	cin>>n;

	int t[n];
	for(int i=0; i<n; ++i) cin>>t[i];

	sort(t,t+n);
	
	int a,b,c;
	
	b=t[0];
	c=t[1];

	for (int i=2; i<n; ++i) {
		a=b;
		b=c;
		c=t[i];

		if((a+b) > c &&
		   (a+c) > b &&
		   (b+c) > a) {
			
			cout<<"YES"<<endl;
			return 0;
		}
		
	}
	
	cout<<"NO"<<endl;
	return 0;
}
