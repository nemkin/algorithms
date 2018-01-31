#include <iostream>
using namespace std;
int main () {

    int rownum, colnum, opnum;

    cin>>rownum>>colnum>>opnum;

    int ops[opnum][3];
    int res[rownum][colnum];

    for(int i=0; i<rownum; ++i) {
        for(int j=0; j<colnum; ++j) {
            res[i][j] = 0;
        }

    }

    bool cbc[colnum], rbc[rownum];

    for(int i=0; i<rownum; ++i) {
        rbc[i]=false;
    }

    for(int j=0; j<colnum; ++j) {
        cbc[j]=false;
    }

    for(int i=opnum-1; 0<=i; --i) {
        cin>>ops[i][0]>>ops[i][1]>>ops[i][2];
        --ops[i][1];

    }

    for(int i=0; i<opnum; ++i) {
        if(ops[i][0] == 1) { // coloring rows
                if (!rbc[ops[i][1]]) {
                    rbc[ops[i][1]] = true;
                    for(int j=0; j<colnum; ++j) {
                        if(!cbc[j]) res[ops[i][1]][j] = ops[i][2];
                    }
                }

        } else { // coloring columns
            if (!cbc[ops[i][1]]) {
                    cbc[ops[i][1]] = true;
                    for(int j=0; j<rownum; ++j) {
                        if(!rbc[j]) res[j][ops[i][1]] = ops[i][2];
                    }
                }

        }
    }

    for(int i=0; i<rownum; ++i) {
        for(int j=0; j<colnum; ++j) {
        cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
