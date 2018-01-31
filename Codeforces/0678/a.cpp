#include <iostream>
using namespace std;
int main () {
	long long n, k;
	cin>>n>>k;
     	
	long long a=n+1;
	long long b=n+k;
	long long tmp;
	if(a%k == 0) {
		cout<<a<<endl;
		return 0;
	}
	while(a<=b) {
		tmp = (a+b)/2;
		if(tmp%k == 0) {
			cout<<tmp<<endl;
			return 0;
		}

		if((a%k)<=(tmp%k)) a = tmp+1;
		else b=tmp-1;
		
	}
	
	return 0;
}
