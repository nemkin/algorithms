#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin>>n;
	long long a[n];

	for(int i=0; i<n; ++i) cin>>a[i];
	
	sort(a, a+n);
	
	long long currentb = 1;	
	int aindex = 0;
	while(aindex<n) {
		if(currentb<=a[aindex]) {
			currentb++;
			aindex++;
		} else {
			aindex++;
		}
	}
	
	cout<<currentb<<endl;
	return 0;
}
