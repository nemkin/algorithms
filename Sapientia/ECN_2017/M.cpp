#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int t[108][108][108];
int val[108][108][108];
int dir[108][108][108];

int main(){

    int tc;
    cin>>tc;
    while (tc --> 0) {

        vector<int> sol;
        int m,n,k;
        scanf("%d %d %d", &m, &n, &k);
        int x[108], y[108], z[108];

        for (int i=1; i<=m; i++) {
            scanf("%d", &x[i]);
        }

        for (int i=1; i<=n; i++) {
            scanf("%d", &y[i]);
        }

        for (int i=1; i<=k; i++) {
            scanf("%d", &z[i]);
        }

        /// t[m][n][k]
        for (int i=0; i<=m; i++) {
            for (int ii=0; ii<=n; ii++) {
                for (int iii=0; iii<=k; iii++) {
                    t[i][ii][0]= 0;
                    t[i][0][iii] = 0;
                    t[0][ii][iii] = 0;
                    //dir[i][ii][0]= -1;
                    //dir[i][0][iii] = -1;
                    //dir[0][ii][iii] = -1;
                    val[i][ii][0]= 100000;
                    val[i][0][iii] = 100000;
                    val[0][ii][iii] = 100000;
                }
            }
        }

        for (int i=1; i<=m; i++) {
            for (int ii=1; ii<=n; ii++) {
                for (int iii=1; iii<=k; iii++) {
                    val[i][ii][iii] = 100000;
                    dir[i][ii][iii] = -1;

                    t[i][ii][iii] = 0;
                    if (x[i] == y[ii] && x[i] == z[iii]) {
                        t[i][ii][iii] = t[i-1][ii-1][iii-1] + 1;
                        val[i][ii][iii] = x[i];
                        dir[i][ii][iii] = 0;
                    }
                    if (t[i-1][ii][iii] >= t[i][ii][iii]) {
                        t[i][ii][iii] = t[i-1][ii][iii];
                        dir[i][ii][iii] = 1;
                    }
                    if (t[i][ii-1][iii] >= t[i][ii][iii]) {
                        t[i][ii][iii] = t[i][ii-1][iii];
                        dir[i][ii][iii] = 2;
                    }
                    if (t[i][ii][iii-1] >= t[i][ii][iii]) {
                        t[i][ii][iii] = t[i][ii][iii-1];
                        dir[i][ii][iii] = 3;
                    }
                    //t[i][ii][iii] = max(t[i][ii][iii], t[i-1][ii][iii]);
                    //t[i][ii][iii] = max(t[i][ii][iii], t[i][ii-1][iii]);
                    //t[i][ii][iii] = max(t[i][ii][iii], t[i][ii][iii-1]);
                }
            }
        }
        if (t[m][n][k] == 0) {
            cout<<"No solution" << endl;
            continue;
        }

        while (m>0 && n>0 && k>0) {
            if (dir[m][n][k] == 0) {
                sol.push_back(val[m][n][k]);
                m--; n--; k--;
            }
            else if (dir[m][n][k] == 1) {
                m--;
            }
            else if (dir[m][n][k] == 2) {
                n--;
            }
            else if (dir[m][n][k] == 3) {
                k--;
            }

        }
        //sol.pop_back();
        reverse(sol.begin(), sol.end());
        //cout<<"[ ";
        for (int i=0; i<sol.size(); i++) {
            if (sol[i] == 100000)
                continue;
            if (i>0) cout<<" ";
            cout<<sol[i];

        }
        //cout<<"]";
        cout<<endl;


    }
    return 0;
}

/*

1
3 3 3
1 2 3
1 3 2
2 3 1



*/
