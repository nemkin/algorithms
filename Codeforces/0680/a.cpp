#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main () {
	int a[5];
	int num[5] = {0};
	int maxsum = 0;
	int allsum = 0;
	for(int i=0; i<5; ++i) { cin>>a[i]; allsum+=a[i];}
	sort(a, a+5);
	
	for(int i=0; i<5; ++i) for(int j=0; j<5; ++j) {
		if(a[i] == a[j]) ++num[i];
	}
	int sum;
	for(int i=4; 0<=i; --i) {
		if(2<=num[i]) {
			sum = a[i] * min(3,num[i]);
			if(maxsum<sum) maxsum = sum;
		} 	
	}
	
	cout<<allsum-maxsum<<endl;	

	return 0;
}
