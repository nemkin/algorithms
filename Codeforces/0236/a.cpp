#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main () {
    int i;
    string a;
    int dist = 0;
    cin>>a;

    for(int i=0; i<a.length(); i++) {
        dist |= 1<<(a[i]-'a');
    }
    i=0;
    i+=dist%2;
    while(0<dist) {
        dist>>=1;
        i+=dist%2;
    }
    cout<<((i%2)?"IGNORE HIM!":"CHAT WITH HER!");
    return 0;
}


