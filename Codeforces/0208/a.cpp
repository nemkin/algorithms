#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    string a;
    int b;
    cin>>a;
    while(-1 != (b = a.find("WUB"))) a.replace(b,3, b!=0 && a[b-1]!=' ' ? " " : "");
    cout<<a<<endl;
    return 0;
}
