#include <iostream>

int abs (int a) {
    if(a<0) a*=-1;
    return a;
}

using namespace std;
int main () {
    int i=0,j=0,x,y, t;
    for(x=1; x<=5;x++) for(y=1;y<=5;y++) {
        cin>>t;
        if(t==1) {
            i=x;
            j=y;
        }
    }
    cout<<abs(3-i)+abs(3-j)<<endl;
    return 0;
}
