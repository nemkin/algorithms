#include <iostream>
using namespace std;
int main () {
    string s, h = "hello";
    cin>>s;
    int j = 0;
    for(int i = 0; i<s.length(); i++) {
        if(h[j] == s[i]) ++j;
    }
    if(j<h.length()) cout<<"NO";
    else cout<<"YES";
    return 0;
}
