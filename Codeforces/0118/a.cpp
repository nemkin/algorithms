#include <iostream>
using namespace std;
int main () {
    int i;
    string a;
    cin>>a;

    for(i=0; i<a.length(); i++) {
        if('A'<=a[i] && a[i]<='Z') a[i] = a[i]-'A'+'a';

        if(a[i]=='a' || a[i]=='o' || a[i]=='y' || a[i]=='e' || a[i]=='u' || a[i]=='i') {
            //Vowel
            // Do nothing.
        } else {
            //Consonant
            cout<<'.'<<a[i];
        }
    }

    return 0;
}
