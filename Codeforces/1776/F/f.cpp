#include <bits/stdc++.h>

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;
int main() {
  int tests; cin>>tests;

  for(int cas=0; cas < tests; ++cas) {
    debug("HALLO BEGIN");
    int n, m; cin>>n>>m;
    int k = 2;
    vector<vector<int>> adj(n, vector<int>());
    vector<bool> reachable_by_specu(n, false);

    int specu, specv; cin>>specu>>specv; --specu; --specv;
    reachable_by_specu[specu] = true;
    reachable_by_specu[specv] = true;
    adj[specu].push_back(specv);
    adj[specv].push_back(specu);

    vector<int> who(m, 0);
    who[0] = 1;

    debug("HALLO READ");
    debug(m);
    for(int i=1; i<m; ++i) {
      int ui, vi; cin>>ui>>vi; --ui; --vi;
      adj[ui].push_back(vi);
      adj[vi].push_back(ui);
      debug(ui, vi);
      if(ui == specu || vi == specu) {
        who[i] = 1;
        reachable_by_specu[ui] = true;
        reachable_by_specu[vi] = true;
      } else {
        who[i] = 2;
      }
    }
    debug(reachable_by_specu);
    debug("HALLO OF");
    if (std::all_of(
          reachable_by_specu.begin(),
          reachable_by_specu.end(),
          [](bool v) { return v; })) {
    // G - specu osszefuggo?

      queue<int> q;
      vector<bool> used(n);
      vector<int> d(n), p(n);
      debug(adj);
      q.push(specv);
      used[specv] = true;
      while (!q.empty()) {
        int v = q.front();
        debug(v);
        q.pop();
        for (int u : adj[v]) {
          debug(u);
          if (u == specu) continue;
          if (!used[u]) {
            used[u] = true;
            q.push(u);
          }
        }
      }

      used[specu] = true;
      debug(used);
    // Igen -> 3. ceg specu - specv el
       if (std::all_of(
          used.begin(),
          used.end(),
          [](bool v) { return v; })) {

          who[0] = 3;
          k = 3;

    // Nem -> 2. ceg specu - specv el
          } else {
            who[0] = 2;
          }

    }

    cout << k << endl;
    for(int i=0; i<m; ++i) {
      cout << who[i] << (i == (m-1) ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}
    
    
