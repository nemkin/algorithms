#include <iostream>
#include <cmath>
using namespace std;

int ways (int n) {
	int ret = 0;
	int maxcube = cbrt(n);
	
	for(int i=2; i<=maxcube; ++i) {
		int cube = i*i*i;
		ret += n/cube;
	}
	return ret;
}

int main() {
	for(int i=1; i<10000000; ++i) {
		int w = ways(i);
		float c = 4.7;
		cout<<i<<" "<<w<<" "<<c*w;
		if(i<c*w) cout<<"NOOO";
		cout<<endl;
	}
	return 0;
}
