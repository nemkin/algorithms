#include <iostream>
#include <cstdio>
#define N 100000
using namespace std;

// Hanyadik elem mod 2
// Utolsó karakter mi volt
// Flippelve nem volt, épp flippelve van, befejeztük a flippelést

int DP[2][2][3];

int main() {

    int n;
    cin>>n;

    int r0;
    int r1;
    int c;
    char tmp;

    for(int i=1; i<=n; ++i) {

        cin>>tmp;
        c = tmp-'0';

        DP[(i%2)][c][0] = DP[(i-1)%2][(c+1)%2][0]+1;
        DP[(i%2)][c][1] = max(DP[(i-1)%2][(c+1)%2][1]+1,DP[(i-1)%2][c][0]+1);
        DP[(i%2)][c][2] = max(DP[(i-1)%2][(c+1)%2][2]+1,DP[(i-1)%2][c][1]+1);

        DP[(i%2)][(c+1)%2][0] = DP[(i-1)%2][(c+1)%2][0];
        DP[(i%2)][(c+1)%2][1] = DP[(i-1)%2][(c+1)%2][1];
        DP[(i%2)][(c+1)%2][2] = DP[(i-1)%2][(c+1)%2][2];
    

        cout<<DP[i%2][0][0]<<DP[i%2][0][1]<<DP[i%2][1][0]<<DP[i%2][1][1]<<endl;
    }
    return 0;
}
