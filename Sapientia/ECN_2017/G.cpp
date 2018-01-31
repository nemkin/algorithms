#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

int main(){



    int n;
    //cin>>n;
    while (scanf("%d", &n) != EOF) {
        //cin>>n;
        int on = n;
        vector<int> oszt;
        if (n == 1) {
            cout<<1<<endl;
      //      cin>>n;
            continue;
        }
        if (n == 2 || n == 3) {
            cout<<-1<<endl;
        //    cin>>n;
            continue;
        }

        for (int i=2; i<=n; i++) {
            if (n % i == 0) {
                if (oszt.size() > 0 && oszt[oszt.size()-1] == i) {
                    cout<<0<<endl;
                   // cout<<"["<<i<<"]\n";
                    goto x;
                }
                oszt.push_back(i);
                n /= i;
                i--;
            }
            if (i > sqrt(on)) {
                oszt.push_back(0);
                break;
            }
        }


        cout <<(oszt.size()%2 == 0 ? 1 : -1 )<< endl;

        x:
            int p=0;

        //cin>>n;
    }

    return 0;
}
