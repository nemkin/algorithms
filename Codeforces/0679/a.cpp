#include <iostream>
using namespace std;
int main() {
	int t, s, x;
	cin>>t>>s>>x;

	if(t<=x && (x!=t+1) && (((x-t)%s)<2)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
