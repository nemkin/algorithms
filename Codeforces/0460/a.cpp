#include <iostream>
using namespace std;
int main () {
    int socks, m, day=0;
    cin>>socks>>m;

    while(true) {
        day++;
        if(socks<=0) break;
        socks--;
        if(!(day%m)) socks++;
    }

    cout<<day-1;

    return 0;
}
