#include <iostream>
#include <vector>

#ifdef LOCAL
  #include "../algo/debug.h"
#else
  #define debug(...) 42
#endif

using namespace std;

typedef long long ll;

int n, m;
vector<ll> a_in;

bool possible(ll time) {

  vector<ll> a = a_in;

  int current_position = n-1;
  while (!a[current_position]) --current_position;

  int current_person = 0;

  while (0 <= current_position && current_person < m) {
    
    current_person += 1;
    ll time_left = time - (current_position + 1);

    while (0 < time_left) {
      ll boxes_to_take = min(a[current_position], time_left);
      time_left -= boxes_to_take;
      a[current_position] -= boxes_to_take;
      
      debug("STEP", current_person, current_position, time_left, boxes_to_take);
      debug(a);

      while (!a[current_position]) --current_position;
    }
  }

  return current_position < 0 && current_person < m;
}

int main() {
  cin >> n >> m;
  a_in.resize(n);
  for(int i=0; i<n; ++i) cin>>a_in[i];

  cout << possible(5) << endl;

  return 0;
}

   

// def binsearch(from, to):
//   if from == to:
//     return from
//   mid = (from + to) // 2
//   if possible(mid):
//     return binsearch(from, mid)
//   else:
//     return binsearch(mid+1, to)

// possible(5)