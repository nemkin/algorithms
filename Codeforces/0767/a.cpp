#include <iostream>
using namespace std;
bool snacks[100001];

int main () {
    int n;
    cin>>n;

    int first = n;
    int snack;
    for(int i=1; i<=n; ++i) {
	cin>>snack;
        snacks[snack] = true;
        
	for(; (0<first)&&(snacks[first]); --first) {
	    cout<<first<<' ';
	}

        if (i!=n) cout<<endl;
    }
    return 0;
}
