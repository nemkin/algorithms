#include <iostream>
#include <algorithm>
using namespace std;



typedef struct place {
    int start;
    int stop;
    int length;
    int db;
} place;

bool cmp (place a, place b) {
    if(a.db>b.db) return true;
    if(a.db == b.db && a.length<b.length) return true;
    return false;
}

place nums[1000001];

int main () {

    int n, i, maxnum=0;
    cin>>n;
    int ar[n];
    for(i=0; i<1000001; ++i) {
         nums[i].start = -1;
         nums[i].stop = -1;
         nums[i].length = -1;
         nums[i].db = 0;
    }

    for(i=0; i<n; ++i) {
        cin>>ar[i];
    }

    for(i=0; i<n; i++) {
        if(nums[ar[i]].db == 0) {
            nums[ar[i]].start = i;
        }
        nums[ar[i]].stop=i;
        ++nums[ar[i]].db;
        nums[ar[i]].length = nums[ar[i]].stop-nums[ar[i]].start+1;
    }
    sort(nums, nums+1000001, cmp);

    cout<<nums[0].start+1<<" "<<nums[0].stop+1;


    return  0;
}
