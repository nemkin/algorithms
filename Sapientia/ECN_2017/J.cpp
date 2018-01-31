#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > e;

int main(){

    int tc;
    cin>>tc;
    while (tc --> 0) {

        int qx[1008];
        int qy[1008];
        int n, k;
        scanf("%d %d", &n, &k);

        for (int i=0; i<e.size(); i++) {
            e[i].clear();
        }

        e.clear();

        e.resize(k+1);

        for (int i=0; i<k; i++) {
            scanf("%d %d", &qx[i], &qy[i]);
            for (int j=0; j<i; j++) {
                if (qx[i] == qx[j] || qy[i] == qy[j] || (qx[i] - qy[i]) == (qx[j] - qy[j]) || ((qx[i] + qy[i]) == (qx[j] + qy[j]))) {
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }

        int comp = 0;
        bool volt[1008];
        int voltdb = 0;
        for (int i=0; i<k+3; i++)
            volt[i] = false;

        queue<int> q;

        while (voltdb != k) {
            for (int i=0; i<k; i++) {
                if (!volt[i]) {
                    q.push(i);
                    comp++;
                    break;
                }
            }

            while (!q.empty()) {
                int id = q.front();
                q.pop();

                if (volt[id])
                    continue;

                volt[id] = true;
                voltdb++;
                for (int iii = 0; iii < e[id].size(); iii++) {
                    int i = e[id][iii];
                    if (!volt[i])
                        q.push(i);
                }
            }
        }

        cout << comp << endl;



    }
    return 0;
}
