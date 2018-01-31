#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int i,n, fh=0, sh=0;
    cin>>n;
    int num[n];

    for(i=0;i<n;++i) {
        cin>>num[i];
        sh+=num[i];
    }

    sort(num, num+n, std::greater<int>());

    for(i=0;i<n;i++) {
        fh+=num[i];
        sh-=num[i];
        if(fh>sh) break;
    }

    cout<<i+1;
    return 0;
}
