#include <iostream>
#include <iomanip>

#define N 2005

bool rows[N];
bool cols[N];

using namespace std;

int main () {

	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout<<fixed<<setprecision(10);

	int n,m;
	cin>>n>>m;
	int r=n,c=n;
	int x,y;

	for(int i=0; i<m; ++i) {

		cin>>x>>y;

		if(!rows[x]) {
			rows[x] = true;
			--r;
		}

		if(!cols[y]) {
			cols[y] = true;
			--c;
		}
	}
	
	double dp[r+1][c+1];

	dp[0][0] = 0.0;

	for(int i=1; i<=r; ++i) {

		dp[i][0] = dp[i-1][0] + (double)n/i;
	}

	for(int j=1; j<=c; ++j) {

		dp[0][j] = dp[0][j-1] + (double)n/j;
	}

	for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j) {

		dp[i][j] = ( n*n + (n-i) * j * dp[i][j-1] + i * (n-j) * dp[i-1][j] + i * j * dp[i-1][j-1] ) / (n*n - (n-i)*(n-j));

	}

	cout<<dp[r][c];

	return 0;
}

