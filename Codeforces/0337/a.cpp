#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int n; // num of students
    int m; // num of puzzles

    cin>>n>>m;

    int puzzles[m];
    int mindiff = 1001;
    int diff;

    for(int i=0; i<m; ++i) cin>>puzzles[i];

    sort(puzzles, puzzles+m);

    for(int i=n-1; i<m; ++i) {
        diff = puzzles[i] - puzzles[i-n+1];
        if(diff<mindiff) mindiff = diff;
    }
    cout<<mindiff<<endl;

    return 0;
}
