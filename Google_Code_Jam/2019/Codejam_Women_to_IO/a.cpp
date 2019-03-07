#include <iostream>

using namespace std;

int main () {

  int cases;
  cin>>cases;

  for(int case_i=1; case_i<=cases; ++case_i) {

    cout<<"Case #"<<case_i<<": ";

    int r,c,k;
    cin>>r>>c>>k;

    if (k == r*c-1) {
      cout<<"IMPOSSIBLE"<<endl;
      continue;
    }

    cout<<"POSSIBLE"<<endl;

    if (c==1) {

      for (int i=0; i<r; ++i) {
        if(i==k) cout<<"S"<<endl;
        else cout<<"N"<<endl;
      }
      continue;
    }

    int k_i=0;
    for (int i=0; i<r; ++i) {
      for (int j=0; j<c; ++j) {
        if(k_i<k) {
          cout<<"N";
          k_i++;
        } else if (i==r-1) {
          if (j==c-1) cout<<"W";
          else cout<<"E";
        } else {
          cout<<"S";
        } 
      }
      cout<<endl;
    }
  }
  return 0;
}

