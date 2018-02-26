#include <iostream>
using namespace std;

int main() {

    long long n;

    cin>>n;

    while(n!=0) {

        string a;
        cin>>a;

        int minc = -1;
        int rcounter = -1;
        int dcounter = -1;

        for(int i=0; i<a.length(); ++i) {

            bool b = false;
            switch(a[i]) {
                case 'Z':
                    cout<<"0"<<endl;
                    goto next;        
                case 'R':
                    rcounter = 1;
                    if (dcounter != -1 && (minc == -1 || dcounter < minc)) {
                       minc = dcounter; 
                    }
                break;
                case 'D':
                    dcounter = 1;
                    if (rcounter != -1 && (minc == -1 || rcounter < minc)) {
                        minc = rcounter;
                    }
                break;
                case '.':
                    if(rcounter!=-1)++rcounter;
                    if(dcounter!=-1)++dcounter;
                break;
            }
        }
        cout<<minc<<endl;
        next: cin>>n;
    }

    return 0;
}
