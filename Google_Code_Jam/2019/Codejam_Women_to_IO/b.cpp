#include <iostream>
#include <vector>

using namespace std;

int main() {



  int cases;
  cin>>cases;

  for(int case_i=1; case_i<=cases; ++case_i) {

    cout<<"Case #"<<case_i<<": ";

    vector<int> h;
    int s;
    cin>>s;
    h.resize(s+1);
    for (int i=0; i<h.size(); ++i) {
      cin>>h[i];
    }

    int counter = 0;

    int last_i = 0;
    int max = h[1];
    int min = h[1];
    for(int i=2; i<h.size(); ++i) {

        if ((h[last_i] < max && max > h[i]) ||
            (h[last_i] > min && min < h[i])) {
        counter += 1;
        last_i = i;
      
        if (i+2 < h.size()) {
          max = h[i+1];
          min = h[i+1];
          i=i+1;
        } else {
          break;
        }
      } else {
        if (max<h[i]) max = h[i];
        if (min>h[i]) min = h[i];
      }
    }

    cout<<counter-1<<endl;
  }

  return 0;
}
