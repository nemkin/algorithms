#include <iostream>
#include <string>
using namespace std;
int main () {
    string a;
    getline(cin, a);

    if(a.find('H')!= string::npos || a.find('Q')!= string::npos || a.find('9')!= string::npos ) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}
