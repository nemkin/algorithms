#include <iostream>
#include <algorithm>

using namespace std;

bool cmp (int a, int b) {
    if(b<a) return true; //Undefined behaviour on b<=a. Oh god why.
    return false;
}

int scores[51];

int main () {

    int i,n,k;
    cin>>n>>k;


    for(i=0; i<n; i++) cin>>scores[i];


    sort(scores, scores+n, cmp);


    for(i=0; i<n; i++) {
        if(scores[i]<=0) break;
        if(scores[i]<scores[k-1]) break;
    }

    cout<<i<<endl;
    return 0;
}
