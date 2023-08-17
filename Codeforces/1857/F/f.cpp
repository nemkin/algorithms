#include <bits/stdc++.h>

using namespace std;

map<long long, int> a;
struct query {
  long long x;

  vector<long long> y;

  vector<long long> count;

  int i;
};
vector<query> q;

typedef std::map<long long, int>::iterator wtf;

bool cmp (const query& a, const query& b) {
  return a.x < b.x;
}

void weird_query_binary_search_idk(int query_first, int query_last, wtf begin, wtf end) {

  long long sum = begin->first + end->first;
  long long prod = begin->first * end->first;

  int qb = query_first;
  int qe = query_last;

  while(qb != qe) {
    int mid = (qb + qe)/2;

    if(q[mid].x == sum) {
      if(q[mid].y == prod) {
        if (begin != end) {
          q[mid].count += begin->second * end->second;
        } else {
          q[mid].count += begin->second * (begin->second-1) / 2;
        }
      }

      break;
    }


  }

}

int main() {
  int t; cin>>t;

  while(t--) {

    int n; cin>>n;

    a.clear();
    
    
    for(int i=0; i<n; ++i) {
        long long ai; cin>>ai;

        a[ai] += 1;
    }

    int qn; cin>>qn;
    q.assign(qn, {});

    for(int qi=0; qi<qn; ++qi) {
      long long x, y; cin>>x>>y;
      
      q[qi].x = x;
      q[qi].y = y;
      q[qi].i = qi;
    }

    sort(q.begin(), q.end(), cmp);

    auto i=a.begin();
    auto j=prev(a.end());
    int qi = 0;
    while(i != j) {

      long long currsum = i->first + j->first;

      if (currsum == q[qi].x) {

        qi++;
      }

      if(a[i] + a[j] < q[qi].x) {

      }

    }

  }

  return 0;
}
