#include <bits/stdc++.h>
#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

typedef struct INDEXED_INT {
  int index;
  int value;

  bool operator < (const INDEXED_INT& o) const
    {
        return (value < o.value);
    }

} INDEXED_INT;

int main() {
  
  int t; cin>>t;

  while(t--) {

    int n; cin>>n;
    int k; cin>>k;
    vector<INDEXED_INT> a(n);
    for(int i=0; i<n; ++i) { 
      cin>>a[i].value; 
      a[i].index = i;
      }

    sort(a.begin(), a.end());

    // for(int i=0; i<n; ++i) {
    //   cout<<a[i].index<<": "<<a[i].value<<", ";
    // }
    // cout<<endl;

    int resi = -1;
    int resj = -1;
    int resx = -1;
    int maxres = -1;

    int mask = (1 << k) - 1;
    for(int i=1; i<n; ++i) {
      int e1 = a[i].value;
      int e2 = a[i-1].value;

      int ones = (e1) & (e2) & mask;
      int zeroes = (~e1) & (~e2) & mask;
      int res = (ones | zeroes);

      if (maxres < res) {
        resi = a[i].index;
        resj = a[i-1].index;
        resx = zeroes;
        maxres = res;
      }


      // cout 
      // << bitset<32>(e1) 
      // << " " 
      // << bitset<32>(e2) 
      // << " " 
      // << bitset<32>(res) 
      // << endl;

    }
    if(resi > resj) {
      swap(resi, resj);
    }
    cout << resi+1 << " " << resj+1 << " " << resx << endl; // " " << maxres
    a.clear();
  }


  return 0;
}