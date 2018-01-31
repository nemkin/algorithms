#include <iostream>
using namespace std;
int main () {
    int k, n, w;
    cin>>k>>n>>w;
    int needed = (w+1)*w/2*k;
    cout<<((needed>n)?(needed-n):0);
    return 0;
}
