#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef long long ll;

int n, m;
vector<ll> a_in;

bool possible(ll time) {
  
  vector<ll> a = a_in;

  int current_position = n-1;
  while (0 <= current_position && !a[current_position]) --current_position;

  int current_person = 0;

  while (0 <= current_position && current_person < m) {
    
    current_person += 1;
    ll time_left = time - (current_position + 1);

    while (0 < time_left && 0 <= current_position) {
      ll boxes_to_take = min(a[current_position], time_left);
      time_left -= boxes_to_take;
      a[current_position] -= boxes_to_take;
      while (0 <= current_position && !a[current_position]) --current_position;
    }
  }

  return current_position < 0 && current_person <= m;
}

ll binsearch(ll from, ll to) {
  if (from == to) return from;
  ll mid = (from + to) / 2;

  if (possible(mid)) {
    return binsearch(from, mid);
  } else {
    return binsearch(mid+1, to);
  }
}

int main() {
  cin >> n >> m;
  a_in.resize(n);
  for(int i=0; i<n; ++i) cin>>a_in[i];

  ll from = 1;
  ll to = accumulate(a_in.begin(), a_in.end(), 0) + n + 1;
  auto result = binsearch(from, to);

  cout << result << endl;

  return 0;
}

   
