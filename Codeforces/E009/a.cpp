#include <iostream>
using namespace std;
int main () {
    int n; //number of buyers
    double p; //cost of apple

    double allapples = 0;
    double freeapples = 0;
    cin>>n>>p;

    string buyer;
    double placetwo = 1;

    for(int i=0; i<n; ++i) {
        cin>>buyer;
        if(buyer.compare("half") == 0) { // "half"
            //allapples += placetwo*0;
        } else { // "halfplus"
            allapples += placetwo;
            ++freeapples;
        }
        placetwo = placetwo*2;
    }

    cout<<(long long)((allapples-freeapples*0.5)*p)<<endl;
    return 0;
}
