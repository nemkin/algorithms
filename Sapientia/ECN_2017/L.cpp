#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    unsigned long long bef, aft;
    cin>>bef>>aft;
    unsigned long long pages[aft];
    for(int i=0; i<aft; ++i) {
        cin>>pages[i];
    }
    sort(pages, pages+aft);
    unsigned long long i=0;
    unsigned long long currbeg = 1;
    unsigned long long currend = 1;

    if( pages[0]!=1 ) cout<<"1-"<<pages[0]-1<<endl;
    for(int i=0; i<aft-1; ++i){
        if(pages[i]+1!=pages[i+1] && pages[i]!=pages[i+1])cout<<pages[i]+1<<"-"<<pages[i+1]-1<<endl;

    }
    if( pages[aft-1]!=bef ) cout<<pages[aft-1]+1<<"-"<<bef<<endl;
    /*(while(true) {
        while(pages[i]==currbeg) {
            ++i;
            ++currbeg;
        }
        if(aft<=i) {
                currend = bef;
                cout<<currbeg<<"-"<<currend<<endl;
                break;
        }
        else currend = pages[i]-1;
        cout<<currbeg<<"-"<<currend<<endl;
    }*/
    return 0;
}
