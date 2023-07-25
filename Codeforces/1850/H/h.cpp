#include <bits/stdc++.h>

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

// Graph
vector<vector<int>> edges;
vector<vector<int>> revedges;
vector<vector<int>> bothedges;
vector<vector<long long>> revlengths;
vector<vector<int>> bothlengths;

// DFS
vector<bool> visited;
vector<int> toposort;

void dfs(int v) {
  visited[v] = true;
  for(int u : edges[v]) if(!visited[u]) {
    dfs(u);
  }
  toposort.push_back(v);
}

// DP
vector<long long> dp;
vector<bool> visited2;

bool dpdfs(int v) {
  if(visited2[v]) return true;
  visited2[v] = true;

  for(int j=0; j<bothedges[v].size(); ++j) {
    auto u = bothedges[v][j];
    auto du = bothlengths[v][j];
    auto coord = dp[v] + du;
    if (dp[u] == -1) {
      dp[u] = coord;
    } else if (dp[u] != coord)  {
      return false;
    }
    dpdfs(u);
  }
  return true;
}

int main() {

  int t; cin>>t;

  while(t--) {


    int n,m; cin>>n>>m;

    edges.clear(); edges.resize(n);

    revedges.clear(); revedges.resize(n);
    revlengths.clear(); revlengths.resize(n);

    bothedges.clear(); bothedges.resize(n);
    bothlengths.clear(); bothlengths.resize(n);

    visited.assign(n, false);
    visited2.assign(n, false);

    toposort.clear();

    for(int i=0; i<m; ++i) {
      int ai, bi; long long di; cin>>ai>>bi>>di; --ai; --bi;

      if(di < 0) {
        swap(ai, bi);
        di *= -1;
      }

      edges[ai].push_back(bi);
      revedges[bi].push_back(ai);
      revlengths[bi].push_back(di);

      
      bothedges[ai].push_back(bi);
      bothlengths[ai].push_back(di);
      bothedges[bi].push_back(ai);
      bothlengths[bi].push_back(-di);
    }

    for (int i = 0; i < n; ++i) if (!visited[i]) {
      dfs(i);
    }

    reverse(toposort.begin(), toposort.end());

    dp.assign(n, -1);
 
    bool bad = false;
    for (int i = 0; i < n; ++i) if (!visited2[i]) {
      dp[i] = 0;
      if (!dpdfs(i)) {
        bad = true;
        cout << "NO" << endl;
        break;
      }
    }

    if (!bad) {
      cout << "YES" << endl;
    }

  }

  return 0;
}
