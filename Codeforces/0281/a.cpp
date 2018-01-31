#include <iostream>
#include <string>
using namespace std;
int main () {
    string a;
    cin>>a;
    if('a'<=a[0] && a[0]<='z') a[0]+='A'-'a';
    cout<<a;
    return 0;
}
