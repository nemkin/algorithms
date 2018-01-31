#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
    double x, y;
} point;

int sign (double number) {
    if(number<0) return -1;
    return 1;
}

double sin (point start, point stop) {
    double vx = stop.x-start.x;
    double vy = stop.y-start.y;
    double length = sqrt(vx*vx+vy*vy);

    return vy/length;
}

double cos (point start, point stop) {
    double vx = stop.x-start.x;
    double vy = stop.y-start.y;
    double length = sqrt(vx*vx+vy*vy);

    return vx/length;
}

int side (point l1, point l2, point p) {

    return -1;
}

 bool inside (point t1, point t2, point t3, point p) {
    if (side(t1,t2,p) == side(t2,t3,p) && side(t2,t3,p) == side(t3,t1,p)) return true;
    return false;
 }

int main () {
    int n;
    //cin>>n;

    point l1,l2,p;

    cin>>l1.x>>l1.y;
    cin>>l2.x>>l2.y;
    cin>>p.x>>p.y;

    cout<<side(l1,l2,p);

    /*point points[n];

    for(int i=0; i<n; ++i) {
        cin>>points[i].x>>points[i].y;
    }

    for(int i=0; i<n; ++i) {
        cout<<points[i].x<<' '<<points[i].y<<endl;
    }

    */

    return 0;
}
