#include <iostream>
#include <cmath>

using namespace std;

int is_min(int res, int o) {

    if (res == -1) {
        return o;
    }

    return min(res,o);
}

int n;
int s[600];
int dp[600][600];

int is_dp(int f, int t) {

    if (t < f) {
        return 0;
    }

    if (f == t) {
        return 1;
    }

    if (f+1 == t) {
        if (s[f] == s[t]) {
            return 1;
        }
        return 2;
    }

    if (dp[f][t] != 0) {
        return dp[f][t];
    }

    int res = -1;
    if (s[f] == s[t]) {
        res = is_dp(f+1, t-1);
    }

    for (int i=f; i<t; ++i) {

         int res1 = is_dp(f,i);
         if (res != -1 && res < res1) {
            continue;
         }

         res = is_min(res, res1 + is_dp(i+1,t));
    }

    dp[f][t] = res;
    return dp[f][t];
}

int main() {

    cin>>n;
    
    for(int i=0; i<n; ++i) {
        cin>>s[i];
    }

    cout<<is_dp(0,n-1)<<endl;
    return 0;
}
 

