#include <iostream>
using namespace std;

bool isPrime (int n) {
    for(int i = 2; i<=n/2; ++i) {
        if(!(n%i)) return false;
    }
    return true;
}

int main () {
    int n;
    cin>>n;
    for(int i = 4; i<n; i++) {
        if(isPrime(i)) continue;
        if(isPrime(n-i)) continue;
        cout<<i<<" "<<n-i;
        break;
    }
    return 0;
}
