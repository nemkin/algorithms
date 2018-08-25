#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct {

    int index;
    int open;
    int close;
} segment;

bool order_by_open(segment a, segment b) {

    if (a.open < b.open) return true;
    if (a.open == b.open && a.close < b.close) return true;
    return false;
}

bool order_by_close(segment a, segment b) {
    
    if (a.close < b.close) return true;
    if (a.close == b.close && a.open > b.open) return true;
    return false;
}

int main() {

    int n;
    cin>>n;

    vector<segment> s_open;

    s_open.resize(n);

    for(int i=0; i<n; ++i) {
        segment a;

        a.index = i;
        cin>>a.open>>a.close;

        s_open[i] = a;
    }

    vector<segment> s_close(s_open);

    sort(s_open.begin(), s_open.end(), order_by_open);
    sort(s_close.begin(), s_close.end(), order_by_close);
   
    int distance1 = s_close[0].close - s_open[n-2].open; 
    int distance2 = s_close[1].close - s_open[n-1].open;
   
    int distance3 = 0;
    
    if(s_close[0].index == s_open[n-1].index) {

        distance3 = s_close[1].close - s_open[n-2].open;
    }
    
    cout<<max(max(max(distance1, distance2), distance3), 0)<<endl; 
    return 0;
}
