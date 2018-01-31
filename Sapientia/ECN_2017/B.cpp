#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int t[1000008];

int main(){
    int tc;
    cin>>tc;
    while (tc --> 0) {

        int n,k;
        scanf("%d %d", &n, &k);
        for (int i=0; i<n; i++) {
            scanf("%d", &t[i]);
        }
        sort(t, t+n);
        cout<<t[k-1]<<endl;
    }
    return 0;
}
