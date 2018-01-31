#include <iostream>
#include <string>
using namespace std;
int main () {
    string a,b;
    cin>>a>>b;

    for(int i=0; i<a.length(); i++) {
        if('A'<=a[i] && a[i]<='Z') a[i] += 'a' - 'A';
    }

    for(int i=0; i<b.length(); i++) {
        if('A'<=b[i] && b[i]<='Z') b[i] += 'a' - 'A';
    }

    int res = a.compare(b);

    if(res == 0) cout<<0;
    if(res <  0) cout<<-1;
    if(res >  0) cout<<1;

    return 0;
}
