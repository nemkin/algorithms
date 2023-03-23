#include <iostream>
#include <vector>
#include <numeric>

#ifdef LOCAL
  #include "../../algo/debug.h"
#else
  #define debug(...) 42
#endif

using namespace std;

typedef long long ll;

int n, m;
vector<ll> a_in;

bool possible(ll time) {
  debug("BEGIN ----", time);
  
  vector<ll> a = a_in;

  int current_position = n-1;
  while (0 <= current_position && !a[current_position]) --current_position;

  int current_person = 0;

  while (0 <= current_position && current_person < m) {
    
    current_person += 1;
    ll time_left = time - (current_position + 1);

    while (0 < time_left && 0 <= current_position) {
      debug("STEP ------");
      debug(current_person);
      debug(current_position);
      debug(time_left);
      debug(a);

      ll boxes_to_take = min(a[current_position], time_left);
      time_left -= boxes_to_take;
      a[current_position] -= boxes_to_take;
      
      debug("AFTER");
      debug(boxes_to_take);
      debug(time_left);
      debug(a);

      while (0 <= current_position && !a[current_position]) --current_position;
    }
  }

  debug("FINAL ------");
  debug(a);

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

   
