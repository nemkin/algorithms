#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct {
	unsigned long long r, h;
} panc;

bool cmp (const panc& a, const panc& b) {
	if(a.r>b.r) return true;
	return false;
}

bool cmph (const panc& a, const panc& b) {
	unsigned long long rima = a.h*2*a.r;
	unsigned long long rimb = b.h*2*b.r;
	if(rima>rimb) return true;
	return false;
}

int main() {
	int t;
	cin>>t;
	cout<<setprecision(9)<<fixed;
	for(int c=1; c<=t; ++c) {

		int n,k;
		cin>>n>>k;

		panc stack[n];

		for(int i=0; i<n; ++i) {
			cin>>stack[i].r>>stack[i].h;
		}

		sort(stack, stack+n, cmp);	


		unsigned long long area;
		unsigned long long  maxarea = 0;
		for(int i=0; i<n-k+1; ++i) {
			sort(stack+i+1, stack+n, cmph);
			area = stack[i].r*stack[i].r;
			for(int j=i; j<i+k; ++j) {
				area += stack[j].h*2*stack[j].r;
			}

			if(area>maxarea) maxarea = area;	

			sort(stack+i+1, stack+n, cmp);
		}
		cout<<"Case #"<<c<<": "<<(double)maxarea*(double)3.141592653589793238462643<<endl;
	}

	return 0;
}
