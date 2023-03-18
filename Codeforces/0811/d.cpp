#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> field;
int x=0, y=0;
char u='U', d='D', l='L', r='R';
vector<vector<bool>> visited;
stack<vector<int>> moves;

char dir(int mx, int my) {
  if(mx==-1) return u;
  if(mx==1) return d;
  if(my==-1) return l;
  /*if(my==1)*/ return r;
}

void step(int mx, int my) {
  int prevx=x, prevy=y;
  cout << dir(mx, my) << endl;
  cin >> x >> y; --x; --y;
  if (prevx == x && prevy == y) {
    if (mx) swap(u, d);
    if (my) swap(l, r);
    step(mx, my);
  }
}

bool dfs(int cx, int cy) {
  cout << "OMG " << cx << " " << cy;
  if (field[cx][cy] == 'F') return true;
  
  visited[cx][cy] = true;

  auto move = [&](int mx, int my) -> bool {
    if (x+mx < 0 || n <= x+mx) return false;
    if (y+my < 0 || m <= y+my) return false;
    if (visited[cx+mx][cy+my] || field[cx+mx][cy+my] == '*') return false;
    if (dfs(cx+mx, cy+my)) {
      moves.push(vector<int>{mx, my});
      return true;
    }
    return false;
  };
  
  return move(-1, 0) || move(1, 0) || move(0, -1) || move(0, 1);
}

int main() {
  cin >> n >> m;
  field.resize(n);
  visited.resize(n, vector<bool>(m));
  for(int i=0; i<n; ++i) {
    cin >> field[i];
  }

  dfs(0, 0);

  while(!moves.empty()) {
    auto m = moves.top(); moves.pop();
    step(m[0], m[1]);
  }

  return 0;
}
