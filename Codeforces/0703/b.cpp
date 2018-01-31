#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long n, k;
    long long nearsum = 0, allcapitalsum = 0;
    long long singlecapitalsum = 0;
    long long singleeverybodysum = 0;
    long long capitalsquare = 0;
    cin>>n>>k;

    long long value[n];
    bool capital[n]; for(int i=0; i<n; ++i) capital[i] = false;


    cin>>value[0];
    singleeverybodysum = value[0];
    for(int i=1; i<n; ++i) {
            cin>>value[i];
            singleeverybodysum+= value[i];

            nearsum+=value[i]*value[i-1];
    }
    nearsum+=value[n-1]*value[0];

    int currcapital = 0;
    for(int i=0; i<k; ++i) {
        cin>>currcapital; --currcapital;
        capital[currcapital] = true;
        singlecapitalsum += value[currcapital];
        capitalsquare += value[currcapital]*value[currcapital];
    }

    allcapitalsum = singlecapitalsum*(singleeverybodysum-singlecapitalsum) + (singlecapitalsum*singlecapitalsum - capitalsquare)/2;

    for(int i=1; i<n; ++i) {
        if(capital[i-1] || capital[i]) allcapitalsum-= value[i-1]*value[i];
    }

    if(capital[0] || capital[n-1]) allcapitalsum-= value[0]*value[n-1];

    cout<<allcapitalsum+nearsum<<endl;
    return 0;
}
