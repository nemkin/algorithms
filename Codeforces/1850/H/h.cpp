#include <bits/stdc++.h>

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

// Graph
vector<vector<int>> edges;
vector<vector<long long>> lengths;

// DFS
long long nextpos;
vector<bool> visited;
vector<long long> pos;

bool dfs(int v) {
  visited[v] = true;
  for(int i=0; i<edges[v].size(); ++i) {
    int u = edges[v][i];
    long long shouldbeat = pos[v] + lengths[v][i];
    if (visited[u]) {
      if (pos[u] != shouldbeat) {
        return false;
      }
    } else {
      pos[u] = shouldbeat;
      nextpos = max(nextpos, shouldbeat+1);
      if(!dfs(u)) return false;
    }
  }
  return true;
}

int main() {

  int t; cin>>t;

  while(t--) {

    int n,m; cin>>n>>m;

    edges.assign(n, {});
    lengths.assign(n, {});

    nextpos = 0;
    visited.assign(n, false);
    pos.assign(n, 0);
    
    for(int i=0; i<m; ++i) {
      int ai, bi; long long di; cin>>ai>>bi>>di; --ai; --bi;

      edges[ai].push_back(bi);
      lengths[ai].push_back(di);

      edges[bi].push_back(ai);
      lengths[bi].push_back(-di);
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) if (!visited[i]) {
      pos[i] = nextpos++;
      if (!dfs(i)) {
        ok = false;
        break;
      }
    }

    cout << (ok ? "YES" : "NO") << endl;
  }

  return 0;
}
