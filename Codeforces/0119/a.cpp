#include <iostream>
using namespace std;

int gcd (int a, int b) {
    int twos = 1;
    while(1<a && 1<b) {
        if(a%2) {
            if(b%2) {
                if(a>b) {
                    a = a-b;
                } else {
                    b = b-a;
                }
            } else {
                b>>=1;
            }

        } else {
            if(b%2) {
                a>>=1;
            } else {
                a>>=1;
                b>>=1;
                twos<<=1;
            }

        }
    }

    if(a==0) {
        return b*twos;
    } else if (a==1) {
        return twos;
    } else {
        if(b==0) {
            return a*twos;
        } else if (b==1) {
            return twos;
        } else {
            //Itt nem kene lennunk.
        }
    }
}


int main () {

    int a,b,n,t;
    cin>>a>>b>>n;
    while(true) {
        t=gcd(a,n);
        if(n<t) {
            cout<<"1";
            break;
        } else {
            n-=t;
        }


        t=gcd(b,n);
        if(n<t) {
            cout<<"0";
            break;
        } else {
            n-=t;
        }
    }
    return 0;
}
