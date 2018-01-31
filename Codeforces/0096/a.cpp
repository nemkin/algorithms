#include <iostream>
#include <string>

using namespace std;
int main () {
    string all;
    char c;
    int db;

    cin>>all;
    if(all.length()<1) {
        cout<<"NO";
        return 0;
    }

    c=all[0];
    db=1;
    for(int i=1;i<all.length();++i) {
        if(c==all[i]) db++;
        else {
            if(7<=db) {
                cout<<"YES";
                return 0;
            } else {
                db=1;
                c=all[i];
            }
        }
    }
    if(7<=db) cout<<"YES";
    else cout<<"NO";
    return 0;
}
