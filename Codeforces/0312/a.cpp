#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

typedef struct tree {
    int x;
    int a;
} tree;

bool cmp (tree a, tree b) {
    if(a.x<b.x) return true;
    return false;
}

int addfunc (int a, tree b) {
    return a+b.a;
}

int main () {
    int n;
    cin>>n;
    n=n+1;

    tree trees[n];

    trees[0].x = 0;
    trees[0].a = 0;

    for(int i=1; i<n; i++) {
        cin>>trees[i].x>>trees[i].a;
    }

    //Order by coordinates.
    sort (trees, trees+n, cmp);

    for(int i=0; i<n; i++) {
    }

    int a, b, m;
    a = 0;
    b = n-1;

    //Binary search for 0.
    while (a<=b) {
        m = (a+b)/2;
        if(trees[m].x == 0) break;
        else if(trees[m].x > 0) b = m-1;
        else a = m+1;

    }

    //Range to sum start and end.
    int rs, re;

    if (2*m == n-1) {
        rs = 0;
        re = n-1;
    } else if (2*m < n-1) {
        rs = 0;
        re = 2*m + 1;
    } else {
        rs = 2*m - n;
        re = n-1;
    }

    int sum = accumulate(trees+rs, trees+re+1, 0, addfunc);

    cout<<sum;
    return  0;
}
