#include <iostream>
#include <algorithm>
using namespace std;
int main () {

    bool first = true;
    string a;
    cin>>a;

    size_t ones = std::count(a.begin(), a.end(), '1');
    size_t twos = std::count(a.begin(), a.end(), '2');
    size_t threes = std::count(a.begin(), a.end(), '3');

    if(0<ones) {
        first = false;
        cout<<'1';
        for(int i=0; i<ones-1; i++) {
            cout<<"+1";
        }
    }

    if (0<twos) {
        if(!first) cout<<'+';
        first = false;
        cout<<'2';
        for(int i=0; i<twos-1; i++) {
            cout<<"+2";
        }
    }

    if (0<threes) {
        if(!first) cout<<'+';
        first = false;
        cout<<'3';
        for(int i=0; i<threes-1; i++) {
            cout<<"+3";
        }

    }

    return 0;
}
