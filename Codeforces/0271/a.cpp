#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

bool allDiffNum (int a) {
    int i, d;
    bool nums[10];
    for(i=0; i<10; i++) nums[i] = false;
    char n[10];
    sprintf(n, "%d", a);
    i = -1;
    while(++i,n[i]!='\0') {
        d = n[i] - '0';
        if(nums[d]) return false;
        else nums[d] = true;
    }
    return true;
}

int main () {
    int num;
    cin>>num;
    num++;
    while(!allDiffNum(num)) num++;
    cout<<num;
}
