#include <iostream>
#include <fstream>
#define IN "C.IN"
#define N 1000


using namespace std;

long long st[N][N];


int hanyfele (int x, int y) {
    int i,j;
    //int s;
    long long sum;
     //cout<<x<<" "<<y<<endl;
    //cout<<st[x][y]<<endl;
     //cin>>s;
    if (x < 0 || y < 0) return 0;
    if(st[x][y] == -1) {
        sum=0;
        for (i=0; i<x; i++) {
            sum+=hanyfele(i,y);
        }
        for(j=0; j<y; j++) {
            sum+=hanyfele(x,j);
        }
        for(i=x-1, j=y-1; 0<=i && 0<=j; i--, j--) {
            sum+=hanyfele(i,j);
        }
        // sum = sum-2*st[x][y];
        st[x][y]=sum;
        //cout<<"--> "<<st[x][y]<<endl;
    }
    return st[x][y];
}

int main() {

    int i, j, c;
    int t, n, x, y;
    ifstream file(IN);

    for(i=0; i<N; i++) for(j=0; j<N; j++) {
        if ((i+j)%2==0) {
                st[i][j] = -1;
        }
        else {
            st[i][j] = 0;
        }
    }
    st[0][0] = 1;
    hanyfele(N-1,N-1);
    st[0][0] = 0;

    for(i=0; i<N; i++) for(j=0; j<N; j++) {
        if(((i+j)%2 == 0) && st[i][j]<=0) cout<<i<<" "<<j<<endl;
    }

    file>>t;

    for(c=0; c<t; c++){

    file>>n>>x>>y;

    cout << st[x-1][n-y] << endl;

    }


    return 0;
}
