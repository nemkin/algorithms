#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct interval {
	long long b, e;

	interval(b,e):b(b),e(e){}
	
	bool operator < (const interval& a) const {
		return (this->e < a.b);
	}
 
	interval& operator* (interval& a) {
			this->b = min(this->b, a.b);
			this->e = max(this->e, a.e);

	}

	interval& operator = (int a) {
		b=a;
		e=a;
		return (*this);
	}

	void operator + (int a) {
		return interval(b+a, e+a);
	}

} interval;



bool cmp (interval a, interval b) {
	return (a.b<b.b || (a.b == b.b && a.e < b.e));
}

int main() {

	set<interval> intervals;
	interval tmp;

	for(int i=0; i<954; ++i) {
		scanf("%lld-%lld",&tmp.b,&tmp.e);
		intervals.insert(tmp);
	}

	interval min = 0;
	while(intervals.contains(min)) min = min+1; 

	cout<<min.b<<endl;	

	

	return 0;
}
