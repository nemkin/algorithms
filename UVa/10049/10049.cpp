#include <iostream>
#include <map>

#define N 2000000000

using namespace std;

map<long long, long long> f;

int main() {

    f[1] = 1;
    f[2] = 2;
    f[4] = 3;

    long long currf = 3;

    for (long long i = 6; i < N; ) {
        
        currf += 1; 
        f[i] =  currf;
        map<long long, long long>::iterator it = f.lower_bound(currf);
        if(it->first != currf) it--;
        i += it->second;
    }

    long long c;
    while(true) {
            
        cin>>c;
        if(c==0) break; 
        map<long long, long long>::iterator it = f.lower_bound(c);
        if(it->first != c) it--;
        cout<<it->second<<endl;
    }

    return 0;    
}
