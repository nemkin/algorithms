#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//#define long long long long

vector< vector<long long> > e;
vector< vector<long long> > ch;

long long p[20008];
bool volt[20008];

long long w[20008];

long long getw(long long id) {
    if (w[id] > 0)
        return w[id];
    long long ww = p[id];
    for (long long i = 0; i<ch[id].size(); i++)
        ww += getw(ch[id][i]);
    w[id] = ww;
    return w[id];
}

int main(){

    long long n;
    scanf("%d", &n);

    e.resize(n+1);
    ch.resize(n+1);


    for (long long i=1; i<=n; i++) {
        scanf("%d", &p[i]);
    }

    for (long long i=1; i<n; i++) {
        long long a,b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for (long long j=0; j<=n; j++)
        volt[j] = false;

    volt[1] = true;
    queue<long long> q;
    q.push(1);

    while (!q.empty()) {
        long long id = q.front();
        q.pop();
        volt[id] = true;
        for (long long k=0; k<e[id].size(); k++) {
            if (!volt[e[id][k]]) {
                volt[e[id][k]]= true;
                q.push(e[id][k]);
                ch[id].push_back(e[id][k]);
            }
        }
    }

    /*for (long long i=1; i<=n; i++) {
        cout << i << ": " <<ch[i].size() << " | ";
        for (long long j=0; j<ch[i].size(); j++)
            cout<<ch[i][j] << " ";
        cout<<endl;
    }*/

    getw(1);

    /*for (long long i=0; i<=n; i++) {
        cout << i <<":  " <<getw(i) << endl;
    }*/

    long long mindiff = 100000000;
    long long capital = 1;

    for (long long i=1; i<=n; i++) {
        long long mn = -1, mx = -1;
        for (long long j=0; j<ch[i].size(); j++) {
            long long ww = getw(ch[i][j]);
            if (mn == -1 || ww < mn)
                mn = ww;
            if (mx == -1 || ww > mx)
                mx = ww;
        }
        if (i != 1) {

            long long ww = getw(1) - getw(i);
            if (mn == -1 || ww < mn)
                mn = ww;
            if (mx == -1 || ww > mx)
                mx = ww;
        }

        if ((mx - mn < mindiff || (mx-mn == mindiff && i < capital)) && e[i].size() >= 2) {
            mindiff = mx-mn;
            capital = i;
        }

        //cout<<i<<" "<<mn<<" "<<mx<<" | " << ww<<endl;
    }

    cout<<capital << " " <<mindiff << endl;


    return 0;
}


