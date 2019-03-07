#include<iostream>
#include<vector>
#include<limits>

using namespace std;

vector<vector<double>> dp;

double& solve(int x, int y) {

  if(dp[x][y] == -1) {

    if(y<x) swap(x,y);

    if(x==0) {

      dp[x][y] = 1.0 + 0.5 * solve(x, y-1) + 0.5 * solve(x+1, y);

    } else if (x==1) {

      dp[x][y] = 4.0*solve(x, y-1)-5.0;

    } else {

      dp[x][y] = 1.0 + 0.5 * solve(x, y-1) + 0.5 * solve(x-1, y);

    }

  }

  dp[y][x] = dp[x][y];
  return dp[x][y];
}

typedef numeric_limits<double> dbl;

int main() {

  cout.precision(dbl::max_digits10);
  cout<<scientific;

  dp.resize(501);
  for (auto& row : dp) row.resize(501);

  for(int i=0; i<dp.size(); ++i) {
    for(int j=0; j<dp[0].size(); ++j) {
      dp[i][j] = -1;
    }
  }

  dp[0][0] = 0;
  dp[1][0] = 3;
  dp[0][1] = 3;
  dp[1][1] = 4;

  int cases;
  cin>>cases;

  for(int case_i=1; case_i<=cases; ++case_i) {
    
    int x,y;
    cin>>x>>y;
    if(x<0) x*=-1;
    if(y<0) y*=-1;

    cout<<"Case #"<<case_i<<": "<<solve(x,y)<<endl;

  }

  return 0;
}
