#include <bits/stdc++.h>

using namespace std;

int main() {

  int n; cin>>n;
  vector<long long> a(n);
  for(int i=0; i<n; ++i) cin>>a[i];

  vector<vector<long long>> dp(2, vector<long long>(n, -1));

  long long maxval = a[0];

  dp[0][0] = a[0];
  dp[0][a[0]] = 0;


  // for(int j=0; j<n; ++j) cout << dp[0][j] << " ";
  // cout<<endl;

  for(int i=1; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      if (j < i) {
        // cout << dp[i][j] << " ";
        continue;
      }

      if(dp[(i-1)%2][j] != -1) {
        dp[i%2][j] = dp[(i-1)%2][j]+a[i];
      }
      if(0<=j-a[i] && dp[i%2][j] < dp[(i-1)%2][j-a[i]]) {
        dp[i%2][j] = dp[(i-1)%2][j-a[i]];
      }

      if (dp[i%2][j] > maxval) {
        maxval = dp[i%2][j];
      }

      // cout << dp[i][j] << " ";

    }

    // cout << endl;

  }

  cout << maxval << endl;

  return 0;
}