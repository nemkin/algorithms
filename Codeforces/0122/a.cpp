#include <iostream>
#include <cstdio>
using namespace std;

bool al[1001];

bool lucky (int a) {
    char n[10];
    sprintf(n, "%d", a);
    int i = 0;
    while(n[i]!='\0') {
        if(n[i]!='4' && n[i]!='7') return false;
        i++;
    }
    return true;
}

int main () {

    int n;
    cin>>n;

    for(int i=4;i<=777;i++) {
        if(lucky(i)) for(int j=i;j<=1000;j+=i) al[j] = true;
    }

    switch(al[n]) {
        case false: cout<<"NO"; break;
        case true: cout<<"YES"; break;
    }

    return 0;

}
