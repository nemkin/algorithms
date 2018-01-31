#include <iostream>
using namespace std;

int n,m,b,mod;
int v[500];
int dp[2][501][501];

int main() {
	cin>>n>>m>>b>>mod;
	for(int i=0; i<n; ++i) cin>>v[i];
	
	dp[0][0][0] = 1;

	for(int x=1;x<=n;++x) {
		for(int y=0; y<=m; ++y) for(int z=0; z<=b; ++z) {
			
			dp[x%2][y][z] = dp[(x+1)%2][y][z];
			
			if(0<=y-1 && 0<=z-v[x-1])
			dp[x%2][y][z]+= dp[x%2][y-1][z-v[x-1]];

			dp[x%2][y][z] = dp[x%2][y][z]%mod; 
		}
	}
		
	int result = 0;
	for(int i=0; i<=b; ++i)	{
		result = (result+dp[n%2][m][i])%mod;
	}
	cout<<result<<endl;

	return 0;
}
