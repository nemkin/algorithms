#include <iostream>
#include <cstdio>
using namespace std;

bool lucky (int a) {
    char n[20];
    sprintf(n, "%d", a);
    int i = 0;
    while(n[i]!='\0') {
        if(n[i]!='4' && n[i] != '7') return false;
        i++;

    }
    return true;
}

int main ()
{
    int s=0;
    string a;
    cin>>a;
    for(int i=0; i<a.length(); i++) {
        if(a[i] == '4' || a[i]=='7') s++;
    }

    if(lucky(s)) cout<<"YES";
    else cout<<"NO";

    return 0;
}
