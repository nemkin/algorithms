#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int sc[n];
	for(int i=0; i<n; ++i) {
		cin>>sc[i];
	}

	int dp[n]; for(int i=0; i<n; ++i) dp[i] = -1;
	dp[0] = 0;

	for(int i=1; i<n; ++i) {
		for(int j=0; j<i; ++j) {
			int e = dp[j];
			if(sc[j] == i+1) {
				e+=1;
			} else {
				e+=(i-j);
			}
			if(dp[i] == -1 || e<dp[i]) dp[i] = e;
		}		

	}
	
	for(int i=0; i<n; ++i) cout<<dp[i]<<' ';
	cout<<endl;
	return 0;
}
