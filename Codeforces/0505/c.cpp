#include <iostream>
#include <cmath>
using namespace std;

int n,d;
int dp[30001][501];
int tres[30001];

int index(int i) {
	return (i-d+250);
}

int main () {

	cin>>n>>d;
	int tmp;
	for(int i=0; i<n; ++i) {
		cin>>tmp;
		tres[tmp]++;
	}

	for(int i = 30000; d<=i; --i) {
			
		for(int j=d-250; j<=d+250; ++j) {
			
			if(1<=j && (i+j)<=30000) {
				dp[i][index(j)] = max(dp[i+j][index(j)],
				       	              dp[i+j][index(j+1)]);
				dp[i][index(j)] = max(dp[i][index(j)],
						      dp[i+j][index(j-1)]);

				if(i==10 && dp[i+j][index(j)]!=0) cout<<j<<endl;
				if(i==10 && dp[i+j][index(j-1)]!=0) cout<<j-1<<endl;
				if(i==10 && dp[i+j][index(j+1)]!=0) cout<<j+1<<endl;
			}
			dp[i][index(j)] += tres[i];
		}		
	}

	for(int i=0; i<=30000; ++i) if( i==10 || i==19 || i==27) {
		for(int j=0; j<501; ++j) {
			cout<<"("<<j<<")"<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;	
	cout<<dp[d][index(d)]<<endl;
	cout<<index(d)<<endl;	
	return 0;
}
