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

int main() {

  int t; cin>>t;

  while(t--) {
    int n; cin>>n;
    int k; cin>>k;

    edges.clear(); edges.resize(n);
    revedges.clear(); revedges.resize(n);
    visited.assign(n, false);

    toposort.clear();

    vector<long long> costs(n);
    for(int i=0; i<n; ++i) cin>>costs[i];

    int tmp;
    for(int i=0; i<k; ++i) {
      cin>>tmp; costs[tmp-1] = 0;
    }

    for(int i=0; i<n; ++i) {
      int m; cin>>m;
      for(int j=0; j<m; ++j) {
        long long e;
        cin>>e;

        revedges[i].push_back(e-1);
        edges[e-1].push_back(i);
      }
    }

    for (int i = 0; i < n; ++i) if (!visited[i]) {
      dfs(i);
    }
    reverse(toposort.begin(), toposort.end());

    for(int j=0; j<n; ++j) {
      int ai = toposort[j];
      if (revedges[ai].size() != 0) {
        long long othercost = 0;
        for(int j=0; j<revedges[ai].size(); ++j) {
          othercost += costs[revedges[ai][j]];
        }

        if (othercost < costs[ai]) costs[ai] = othercost;
      }
    }


    for(int i=0; i<n; ++i) {
      cout<<costs[i]<<" ";
    }
    cout<<endl;

  }

  return 0;
}