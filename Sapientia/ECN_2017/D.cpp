#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int mem[4000][4000];
string decode = "!@_-+.;?/:ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int modpow(int a){
    if(a == 0) return 1;
    if(a == 1) return 17;
    int res = modpow(a/2);
    res = res*res;
    if(a%2) res*=17;
    return res%37;
}

int main(){

    int px = 500;
    int py = 500;
    int reg = 0;
    string in;
    cin>>in;
    int rep = 1;
    for(int i=0; i<in.length(); i+=4){
        int instruction = (in[i]-'0')*8 + (in[i+1]-'0')*4 + (in[i+2]-'0')*2 + (in[i+3]-'0');
        //cout<<reg<<endl;

        if( instruction == 1 ){
            rep*=3;
            continue;
        }
        if( instruction == 2 ){
            rep*=4;
            continue;
        }
        if( instruction == 3 ){
            break;
        }

        for(int j=0; j<rep; j++){

            if( instruction == 4 ){ /// clear memory
                for(int k=0; k<1000; k++)
                for(int l=0; l<1000; l++)
                    mem[k][l]=0;
            }
            if( instruction == 5 ){ /// reset pointer
                px = 500;
                py = 500;
            }
            if( instruction == 6 ){ /// reset register
                reg = 0;
            }
            if( instruction == 7 ){ /// increment register
                reg++;
                reg = reg%37;
            }

            if( instruction == 8 ){ /// move pointer right
                px++;
            }
            if( instruction == 9 ){ /// move pointer up
                py++;
            }
            if( instruction == 10 ){ /// move pointer left
                px--;
            }
            if( instruction == 11 ){ /// move pointer down
                py--;
            }

            if( instruction == 12 ){ /// write mem
                mem[px][py] = reg;
            }
            if( instruction == 13 ){ /// write output
                cout<<decode[reg-1];
            }
            if( instruction == 14 ){ /// write mem mod
                //cout<<modpow(reg)<<endl;
                mem[px][py] = modpow(reg);
            }
            if( instruction == 15 ){ /// read mem
                reg = mem[px][py]%37;
            }
        }
        rep=1;
    }
    return 0;
}

