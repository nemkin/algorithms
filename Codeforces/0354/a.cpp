#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    int n,l,r,ql,qr;
    cin>>n>>l>>r>>ql>>qr;
    int w[n];
    for(int i=0; i<n; ++i) cin>>w[i];

    int energy = 0;
    for(int i=0; i<n; ++i) {
        energy+=w[i]*r;
    }
   
    int plus = n-1;
    int fullenergy = energy + plus*qr;
    //cout<<energy<<" "<<plus<<" "<<fullenergy-energy<<" "<<fullenergy<<endl;
   

    int minenergy = fullenergy; 
    for(int i=0; i<n; ++i) {
        energy-=w[i]*r;
        energy+=w[i]*l;
       
        int left = n-i-1;
        int right = i+1;
        plus = abs(left-right);
        
        plus--;
        if(left == right) plus = 0;

        fullenergy = energy;
        if(left>right) fullenergy += plus*qr;
        else fullenergy += plus*ql;

        if(minenergy>fullenergy) minenergy = fullenergy;
        //cout<<energy<<" "<<plus<<" "<<fullenergy-energy<<" "<<fullenergy<<endl;

    }
   
    cout<<minenergy<<endl; 

    return 0;
}
