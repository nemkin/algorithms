#include <iostream>
#include <algorithm>

using namespace std;

typedef struct gift {
    int from, to;
} gift;

bool cmp (gift a, gift b) {
    if(a.to<b.to) return true;
    return false;
}

int main () {

    int n;
    cin>>n;

    gift gifts[n];

    for(int i=0; i<n; i++) {
        gifts[i].from = i+1;
        cin>>gifts[i].to;
    }

    sort(gifts, gifts+n, cmp);

    for(int i=0; i<n; i++) {
        cout<<gifts[i].from<<" ";
    }

    return 0;
}
