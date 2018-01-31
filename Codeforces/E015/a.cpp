#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int prev;
    int curr;
    cin>>prev;
    int maxlength = 1;
    int length = 1;
    for(int i=1; i<n; ++i) {
        cin>>curr;
        if(prev < curr) {
            ++length;
        } else {
            length = 1;
        }
        if(maxlength < length) maxlength = length;
        prev=curr;
    }
    cout<<maxlength<<endl;
    return 0;
}
