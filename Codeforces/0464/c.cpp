#include <iostream>
#include <stack>
#include <string>
#include <cmath>

#define MODULO 1000000007

using namespace std;

typedef struct {
    unsigned long long len;
    unsigned long long num;
} REP;

typedef struct {
    unsigned long long digit;
    string numstr;
    unsigned long long len;
} QUERY;



unsigned long long mod_pow(unsigned long long num, unsigned long long pow, unsigned long long mod) {
   
    unsigned long long res = 1;
    unsigned long long sq = num%mod;
    
    for(; pow; pow>>=1) {
        if (pow & 1) {
            res *= sq;
            res = res%mod;
        }
        
        sq = (sq*sq)%mod;
    }

    return res;
}

int main() {

    string number;

    REP rep[10];
    REP reptmp;
    reptmp.len = 1;
    for(int i=0; i<10; ++i) {
        reptmp.num = i;
        rep[i] = reptmp;
    }    

    string tmp;
    stack<QUERY> q;
    QUERY r;

    cin>>number;

    unsigned long long n;
    cin>>n;

    for(unsigned long long i=0; i<n; ++i) {
        cin>>r.digit;
        cin>>tmp;
        tmp = tmp.substr(2,tmp.length());

        if(tmp!="") {
            r.numstr = tmp;
            r.len = tmp.length();
        } else {
            r.numstr = '0';
            r.len = 0;
        }
        q.push(r);
    }

    while(!q.empty()) {
        
        QUERY r = q.top();
        
        REP result;
        result.num = 0;
        result.len = 0;

        cout<<"Query "<<r.digit<<" -> "<<r.numstr<<" "<<r.len<<endl;

        for(unsigned long long i=0; i<r.len; ++i) {


            unsigned long long first = r.numstr[i]-'0';

            cout<<"Digit: "<<first<<endl;
            cout<<"Mod pow params: 10^"<<rep[first].len<<endl;
            result.num *= mod_pow(10,rep[first].len,MODULO);

            cout<<"Mod pow finished."<<endl;

            cout<<result.num<<endl;

            result.num = result.num%MODULO;
            
            result.num += rep[first].num;
            result.num = result.num%MODULO;
            
            result.len += rep[first].len;
    
            cout<<"Digit finished."<<endl;
        }
       

        cout<<"Representations"<<endl;

        for(unsigned long long i=0; i<10; ++i) {
            cout<<i<<" -> "<<rep[i].num<<" "<<rep[i].len<<endl;
        }
 
        rep[r.digit] = result;
        
        q.pop();      
    }
       
    unsigned long long finalresult = 0;

    for(unsigned long long i=0; i<number.length(); ++i) {

        unsigned long long first = number[i]-'0';
        finalresult *= mod_pow(10,rep[first].len,MODULO);
        finalresult  = finalresult%MODULO;
            
        finalresult += rep[first].num;
        finalresult = finalresult%MODULO;
    }


    cout<<finalresult<<endl;

    return 0;
}

