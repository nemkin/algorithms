#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const double pi = acos(-1);

typedef struct Vec {
	
	int x,y;
	double fi;
	
	Vec(int x, int y, float rot) {
		this->x = x;
		this->y = y;
		this->fi = atan((double)y/((double)x + 0.000001)) + rot;
	}
	
	const bool operator< (const Vec& v) {
		return this->fi < v.fi;
	}
} Vec;

int main() {

    int n;
    vector< pair<int,int> > t;

    scanf("%d", &n);

    int kisebb=0, nagyobb=0;

    int x, y;
    scanf("%d %d", &x, &y);

    for (int i=0; i<n-1; i++) {
		int a,b;
        scanf("%d %d", &a, &b);
        if (a>x && b>y) {
            nagyobb++;
        }
        else if (a<x && b<y) {
            kisebb++;
        }
        else {
            t.push_back(make_pair(a,b));
        }
    }

	/*
	cout<<"kisebb:"<<kisebb<<" nagyobb:"<<nagyobb<<endl;
    for (auto v : t)
        cout<<v.first<<" "<<v.second<<endl;
	*/
	
	vector< Vec > bf;
	vector< Vec > ja;
	
	for (auto v : t) {
		if (v.first <= x && v.second >= y) {
			bf.push_back(Vec(v.first - x, v.second - y, pi/2 ));
		}
		else {
			ja.push_back(Vec(v.first - x, v.second - y, pi/2 ));
		}
	}
	
	sort(bf.begin(), bf.end() );
	sort(ja.begin(), ja.end() );
	
	cout<<"bf:"<<endl;
	for( auto v : bf ) {
		cout<<v.x<<" "<<v.y<<" "<<v.fi*180/pi<<endl;
	}
	
	cout<<"ja:"<<endl;
	for( auto v : ja ) {
		cout<<v.x<<" "<<v.y<<" "<<v.fi*180/pi<<endl;
	}
	
	int bfpos=0, japos=0;
	
	int curr = ja.size();
	int maxcurr = curr;
	int mincurr = curr;
	int bflen = bf.size();
	int jalen = ja.size();
	
	if (bflen == 0 || jalen == 0) {
		cout<<kisebb<<" "<<kisebb+max(bflen, jalen) << endl;
		return 0;
	}
	
	double eps = 0.00001;
	
	while (bfpos <= bflen) {
		while (ja[japos].fi < bf[bfpos].fi + eps && japos < jalen) {
			japos++;
		}
		curr = bflen - bfpos + japos;
		cout << bfpos << " " << bf[bfpos].fi*180/pi << " " << japos << " " << ja[japos].fi*180/pi << endl;
		
		maxcurr = max(curr, maxcurr);
		
		mincurr = min(curr, mincurr);
		
		bfpos++;
	}
	
	cout<<mincurr+kisebb<<" "<<maxcurr+kisebb<<endl;
	//cout<<maxcurr<<endl;
	
	
	
	
    
}
