#include <iostream>
#include <string>
using namespace std;

bool isUpper (char a) {
    return ('A'<=a && a<='Z');
}

bool isLower (char a) {
    return ('a'<=a && a<='z');
}


int main () {

    int i,n;
    string szo;
    bool caps = true;
    cin>>szo;
    n = szo.length();

    for(i = 1; i < n; i++) {
        if (!isUpper(szo[i])) caps = false;
    }

    if(caps) {
        for(i=0; i<n; i++) {
            if(isUpper(szo[i])) {
                szo[i] += 'a' - 'A';
            } else if (isLower(szo[i])){
                szo[i] += 'A' - 'a';
            }
        }
    }

    cout<<szo;

    return 0;
}
