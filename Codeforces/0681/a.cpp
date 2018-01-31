#include <iostream>
using namespace std;
int main () {
	string name;
	int before, after;
	int n;
	cin>>n;
	for(int i=0; i<n; ++i) {
		cin>>name>>before>>after;
		if(2400<=before && before<after) {
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
