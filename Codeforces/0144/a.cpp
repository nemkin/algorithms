#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int num;
    cin>>num;
    int heights[num];
    for(int i=0;i<num;++i) cin>>heights[i];

    int maxplace = (int)(max_element(heights, heights+num) - heights);

    reverse(heights, heights+num);

    int minplace = (int)(min_element(heights, heights+num) - heights);

    int t = maxplace + minplace;

    if(maxplace + minplace + 2 > num) --t;

    cout<<t<<endl;

    return 0;
}
