#include <iostream>
using namespace std;
int main () {

	long long n;
	cin>>n;

	long long lastT[n-1];

	for(long long i=0; i<(n-1); ++i) {
		cin>>lastT[i];
		--lastT[i]; //0 base
	}

	long long ro[n+1]={0};
	long long sum[n+1]={0};
	
	sum[n-1] = 1;
	ro[n-1] = 1;

	for(long long i=n-2; 0<=i; --i) {
		if(i+1<=lastT[i])  ro[i] = sum[i+1]-sum[lastT[i]+1];
		sum[i] = ro[i] + sum[i+1];
	}
	for(int i=0; i<n+1; ++i) {
		cout<<i<<' '<<ro[i]<<' '<<sum[i]<<endl;
	}
	cout<<sum[0]<<endl;
	return 0;
}
