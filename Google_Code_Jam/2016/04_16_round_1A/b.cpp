#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin>>t;
	for(int c=1; c<=t; ++c) {
		int n;
		cin>>n;
	        
		int heights[2501] = {0};	
		int tmp;
		for(int i=0; i<2*n-1; ++i)
			for(int j=0; j<n; ++j) {
				cin>>tmp;
				++heights[tmp];

			}
		cout<<"Case #"<<c<<": ";
		for(int i=1; i<=2500; ++i)
			if(heights[i]%2==1) cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}
