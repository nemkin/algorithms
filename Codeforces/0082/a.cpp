#include <iostream>
using namespace std;
int main () {
    int n;
    cin>>n;
    n = n-1;
    while(!(0<=n && n<=4)) {
        n -= 5;
        n /= 2;
    }

    switch (n) {
        case 0: cout<<"Sheldon"; break;
        case 1: cout<<"Leonard"; break;
        case 2: cout<<"Penny";   break;
        case 3: cout<<"Rajesh";  break;
        case 4: cout<<"Howard";  break;
    }

    return 0;
}
