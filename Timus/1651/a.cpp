#include<bits/stdc++.h>

using namespace std;

int main() {

  int n;
  cin >> n;
  int v=0;
  vector<int> a(n);
  for(int i=0; i<n; ++i) {
    cin>>a[i];
    if(a[i]>v) {
      v=a[i];
    }
    --a[i];
  }

  vector<int> dist(v, numeric_limits<int>::max());
  vector<int> parent(v, -1);

  dist[a[0]] = 0;
  parent[a[0]] = -2;
  for(int i=1; i<n; ++i) {

    int newdist = dist[a[i-1]]+1;

    if(parent[a[i]] == -1 || newdist < dist[a[i]]) {
      dist[a[i]] = newdist;
      parent[a[i]] = a[i-1];
    }

  }

  int curr = a[n-1];
  stack<int> result;
  while(curr != -2) {
    result.push(curr + 1);
    curr = parent[curr];
  }

  while(!result.empty()) {
    cout << result.top();
    result.pop();
    if(!result.empty()) {
      cout << " ";
    }
  }

  return 0;
}