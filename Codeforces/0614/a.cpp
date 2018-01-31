#include <iostream>
using namespace std;
int main () {
    bool had=false;
    long rangestart, rangefinish, base, num;
    cin>>rangestart>>rangefinish>>base;
    for(num = 1; rangestart<=num && num<=rangefinish; num*=base) {
        cout<<num<<' ';
        had = true;
    }
    if(!had) cout<<"-1";
    cout<<endl;
    return 0;
}
