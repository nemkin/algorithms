#include <iostream>
using namespace std;
int main () {
    int k;
    long long n, powtwo, sumtwo;
    cin>>k;
    for(int i=0; i<k; ++i) {
       cin>>n;
       powtwo = 1;
       sumtwo = 0;
       while(powtwo<=n){
           sumtwo+=powtwo;
           powtwo = powtwo<<1;
       }
       cout<<n*(n+1)/2-2*sumtwo<<endl;
    }
    return 0;
}
