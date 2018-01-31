#include <iostream>
using namespace std;
int main() {
	long long a,b,c;
	cin>>a>>b>>c;
	
	if(a==b) {
		cout<<"YES"<<endl;
		return 0;
	}
	if(c==0) {
		cout<<"NO"<<endl;
		return 0;
	}
	if((b-a)%c==0 && 0<=(b-a)*c) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
	return 0;
}
