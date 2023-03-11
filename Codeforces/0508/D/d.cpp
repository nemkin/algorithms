#include <bits/stdc++.h>
using namespace std;

#define MAX_V 5000 // > (26*2 + 10)^2

vector<vector<int>> graph;
stack<int> path;
vector<bool> found;

void euler(int v) {
  found[v] = true;
  for (int i = 0; i < graph[v].size(); ++i)
    if (graph[v][i]) {
      graph[v][i] -= 1;
      euler(i);
    }
  path.push(v);
}

int main() {
  int n, parts;
  map<string, int> vertices;
  vector<string> vertices_reverse;

  cin >> parts;
  graph.resize(MAX_V, vector<int>(MAX_V, 0));
  vertices_reverse.resize(MAX_V);

  for (int i = 0; i < parts; ++i) {
    string triplet;
    cin >> triplet;
    string first = triplet.substr(0, 2);
    string second = triplet.substr(1, 2);

    auto fi = vertices.insert(make_pair(first, vertices.size())).first->second;
    auto si = vertices.insert(make_pair(second, vertices.size())).first->second;

    vertices_reverse[fi] = first;
    vertices_reverse[si] = second;

    graph[fi][si] += 1;
  }
  
  n = vertices.size();

  vector<int> in_degrees(n, 0);
  vector<int> out_degrees(n, 0);
  for (int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      in_degrees[j] += graph[i][j];
      out_degrees[i] += graph[i][j];
    }
  }

  int starter = -1;
  int ender = -1;
  for (int i = 0; i < n; ++i) {
    if(in_degrees[i] == out_degrees[i]) {
      // ok
    } else if (in_degrees[i] + 1 == out_degrees[i] && starter == -1) {
      starter = i;
    } else if (in_degrees[i] == out_degrees[i] + 1 && ender == -1) {
      ender = i;
    } else {
        cout << "NO" << endl;
        return 0;
    }
  }

  found.resize(n, false);
  if (starter == -1) {
    euler(0);
  } else {
    euler(starter);
  }

  // connected?
  for(int i=0; i<n; ++i) {
    if(!found[i]) {
        cout << "NO" << endl;
        return 0;
    }
  }

  cout << "YES" << endl;
  string password;
  while (!path.empty()) {
    string part = vertices_reverse[path.top()]; path.pop();
    if (password == "") {
      password = part;
    } else {
      password += part[1];
    }
  }
  cout << password << endl;

  return 0;
}
