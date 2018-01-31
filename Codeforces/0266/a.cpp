#include <iostream>
#include <string>
using namespace std;
int main () {
    int l;
    cin>>l;

    string rgb;
    cin>>rgb;

    int x=1;
    for(int i=1; i<l; i++) {
        if(rgb[i-1] != rgb[i]) x++;
    }
    cout<<l-x;
    return 0;
}
