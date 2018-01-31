#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct {
	int r, h;
} panc;

bool cmp (const panc& a, const panc& b) {
	if(a.r>b.r) return true;
	return false;
}

bool cmph (const panc& a, const panc& b) {
	double rima = a.h*2*a.r;
	double rimb = b.h*2*b.r;
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
			cout<<"Calc area"<<endl;
			area = stack[i].r*stack[i].r;
			cout<<area<<endl;	
			for(int j=i; j<i+k; ++j) {
				area += stack[j].h*2*stack[j].r;
				cout<<area<<endl;
			}

			if(area>maxarea) maxarea = area;	

			cout<<"Maxarea found"<<endl;
			cout<<maxarea<<endl;
			for(int l=i; l<i+k; ++l) {
				cout<<stack[l].r<<' '<<stack[l].h<<endl;

			}
			cout<<endl;

			sort(stack+i+1, stack+n, cmp);
		}
		cout<<"Case #"<<c<<": "<<(double)maxarea*3.1415926535<<endl;
	}

	return 0;
}
