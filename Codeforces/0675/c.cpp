#include <iostream>
using namespace std;
int main () {
	long long n;
	cin>>n;
	
	long long a[n];
	
	cin>>a[0];

	long long skipped = 0;

	long long i=1;
	for(long long j=1; j<n; ++j) {
		cin>>a[i];
		
		if(a[i-1]!=0 && a[i]!=0) {
			a[i-1] = a[i-1]+a[i];
			++skipped;
		} else {
			++i;
		}
	}

	long long size = i;

	if(a[0]!=0 && a[size-1]!=0) {
		a[0] = a[0]+a[size-1];
		--size;
		++skipped;
	}
	
	long long zeroseq=0;
	long long maxzeroseq=0;
	
	
	for(i=0; i<size; ++i) {
		if(a[i] == 0) {
			++zeroseq;
		} else {
			if(maxzeroseq<zeroseq) maxzeroseq=zeroseq;
			zeroseq=0;
		}
	}
	
	if(zeroseq == size) {
		cout<<skipped<<endl;
		return 0;
	}

	if(zeroseq!=0) {
		i=0;
		while(a[i]==0) {
			++zeroseq;
			++i;
		}

		if(maxzeroseq<zeroseq) maxzeroseq=zeroseq;
	}
	
	cout<<(size-maxzeroseq-1)+skipped<<endl;
	
	return 0;
}
