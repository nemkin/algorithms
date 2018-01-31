#include <iostream>
using namespace std;
int main () {
    int x, y;
    cin>>x>>y;
    cout<<(x/2)*(y/2)*2+(x%2)*(y/2)+(y%2)*(x/2);
    return 0;
}
