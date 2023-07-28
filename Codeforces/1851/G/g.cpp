#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../../algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

int n; // Number of vertices = mountains.
int m; // Number of edges = roads.
int q; // Number of queries.

vector<int> h; // Mountain heights.
vector<vector<int>> edges; // Edge list.

struct mountain {
  int i; // Index of mountain.
  int h; // Height of mountain.
};

bool sort_mountain_by_height(const mountain& a, const mountain& b) {
  return a.h < b.h;
}

struct query {
  int i; // Index of query.
  int a, b; // Start -> End mountain index.
  int e; // Energy level of guy.

  bool r; // Result.

  int maxp() const { return h[a] + e; } // Max potential.
};

bool sort_query_by_p(const query& a, const query& b) { // Sort by potential.
  return a.maxp() < b.maxp();
}

bool sort_query_by_i(const query& a, const query& b) { // Sort by index.
  return a.i < b.i;
}

vector<mountain> mountains;
vector<query> queries;

// DSU
vector<int> dsu_parent;
vector<int> dsu_size;

int dsu_find_set(int v) {
  if (v == dsu_parent[v]) return v;
  return dsu_parent[v] = dsu_find_set(dsu_parent[v]);
}

void dsu_union(int a, int b) {
  a = dsu_find_set(a);
  b = dsu_find_set(b);
  if (a!=b) {
    if(dsu_size[a] < dsu_size[b]) swap(a, b);
    dsu_parent[b] = a;
    dsu_size[a] += b;
  }
}

int main() {

  int t; cin>>t;

  while(t--) {
    cin >> n >> m;

    h.assign(n, 0);
    edges.assign(n, {});
    mountains.assign(n, {});


    for(int i=0; i<n; ++i) {
      cin>>h[i];
      mountains[i].i = i;
      mountains[i].h = h[i];
    }

    for(int i=0; i<m; ++i) {
      int u, v; cin>>u>>v; --u; --v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }

    cin>>q;
    queries.assign(q, {});

    for(int i=0; i<q; ++i) {
      int a,b,e; cin>>a>>b>>e; --a; --b;
      queries[i].i = i;
      queries[i].a = a;
      queries[i].b = b;
      queries[i].e = e;
    }

    sort(mountains.begin(), mountains.end(), sort_mountain_by_height);
    sort(queries.begin(), queries.end(), sort_query_by_p);

    // Init DSU
    dsu_parent.clear(); for(int i=0; i<n; ++i) dsu_parent.push_back(i);
    dsu_size.assign(n, 1);

    int mi = 0;
    for(int qi=0; qi<q; ++qi) {
      int maxp = queries[qi].maxp();

      while(mi < n && mountains[mi].h <= maxp) {
        int i = mountains[mi].i;
        for(int ej=0; ej<edges[i].size(); ++ej) {
          int j = edges[i][ej];
          if (h[j] <= maxp) {
            dsu_union(i, j);
          }
        }
        ++mi;
      }

      debug(dsu_parent);
      
      queries[qi].r = (dsu_find_set(queries[qi].a) == dsu_find_set(queries[qi].b));
    }

    sort(queries.begin(), queries.end(), sort_query_by_p);

    cout << endl << endl << "Mountains" << endl;
    for(int i=0; i<n; ++i) {
      cout<<"i:"<<mountains[i].i<<" h:"<<mountains[i].h<<endl;
    }

    cout << endl << endl << "Queries" << endl;
    for(int i=0; i<q; ++i) {
      cout<<"i:"<<queries[i].i<<" a:"<<queries[i].a<<" b:"<<queries[i].b<<" e:"<<queries[i].e<<" h[a]:"<<h[queries[i].a]<<" r:"<<queries[i].r<<endl;
    }
  }

  return 0;
}
