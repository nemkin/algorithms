#include <iostream>
using namespace std;
int main () {
    int n, t;
    string child;

    cin>>n>>t>>child;

    for(int j=0; j<t; ++j)
    for(int i=0; i<n-1; ++i) {
        if(child[i] == 'B' && child[i+1] == 'G') {
        child[i] = 'G';
        child[i+1] = 'B';
        ++i;
        }
    }
    cout<<child<<endl;
    return 0;
}
