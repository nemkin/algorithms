#include <iostream>
using namespace std;
int main () {
    string magnet;
    string prevmagnet;
    int num;
    int groups;

    cin>>num;
    cin>>prevmagnet;
    groups = 1;

    for(int i=1; i<num; ++i) {
        cin>>magnet;
        if(prevmagnet[1] == magnet[0]) ++groups;
        prevmagnet = magnet;
    }
    cout<<groups<<endl;
    return 0;
}
