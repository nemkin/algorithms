#include <iostream>
using namespace std;
int main() {
	long long sum = 1;
	cout<<sum<<endl;
	for(int i=2; i<=35; ++i) {
		sum=sum*3;
		if(i%2 == 0) sum+=2;
		else sum-=2;
		cout<<sum<<endl;
	}
	cout<<sum<<endl;
	return 0;
}
