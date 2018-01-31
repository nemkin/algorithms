#include <iostream>
using namespace std;
int main() {
    int m, c, n, mcount=0, ccount=0;
    cin>>n;
    for(int i=0; i<n; ++i) {
        cin>>m>>c;
        if(m<c) ++ccount;
        if(c<m) ++mcount;
    }
    if(ccount<mcount) cout<<"Mishka"<<endl;
    if(mcount<ccount) cout<<"Chris"<<endl;
    if(mcount==ccount) cout<<"Friendship is magic!^^"<<endl;
    return 0;
}
