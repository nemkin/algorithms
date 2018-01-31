#include <iostream>
using namespace std;
int main () {
    int n, db, maxdb=0;
    cin>>n;
    db = 1;
    int prev, now;
    cin>>prev;
    for(int i=1; i<n; ++i) {
        cin>>now;
        if(prev<=now)  {
            ++db;
        } else {
            if(db>maxdb) maxdb = db;
            db=1;
        }
        prev = now;
    }
    if(db>maxdb) maxdb=db;
    cout<<maxdb<<endl;
    return 0;
}
