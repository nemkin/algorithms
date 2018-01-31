#include <iostream>

using namespace std;

int main () {

    int n,p;
    string a;
    cin>>n>>p;
    cin>>a;

    if(p==1) {
        cout<<"NO"<<endl;
        return 0;
    }

    if(p==2) {
        if(a=="a") cout<<"b"<<endl;
        if(a=="b") cout<<"NO"<<endl;
        if(a=="ab") cout<<"ba"<<endl;
        if(a=="ba") cout<<"NO"<<endl;
        return 0;
    }
    
    int i = n-1;

    while(0<=i) {
        //cout<<"Index: "<<i<<endl;
        while(0<= i && (p-1)<=(a[i]-'a')) --i;
        //cout<<"Modifying: "<<i<<endl;
        if(i<0) break; 
        
        do {
            a[i]++;
            //cout<<"To: "<<a[i]<<endl;
            //cout<<"Testing on: "<<endl;
            //if(0<=i-1) cout<<i-1<<"th: "<<a[i-1]<<endl;
            //if(0<=i-2) cout<<i-2<<"th: "<<a[i-2]<<endl;
        } while ((((0<=i-1) && (a[i-1] == a[i])) || ((0<=i-2) && (a[i-2] == a[i]))) && ((a[i]-'a')<p));

        if((a[i]-'a')<p) break;
    }

    if(i<0) {
        cout<<"NO"<<endl;
        return 0;
    }

    for(++i;i<n; ++i) {
        if(a[i-1] != 'a' && (i-2<0 || a[i-2] != 'a')) a[i] = 'a';
        else if(a[i-1] != 'b' && (i-2<0 || a[i-2] != 'b')) a[i] = 'b';
        else a[i] = 'c';
    }
    
    cout<<a<<endl;

    return 0;
}
