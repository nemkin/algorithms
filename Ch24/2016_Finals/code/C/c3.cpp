#include <iostream>
#include <cmath>
#include <utility>
#include <cstdio>
using namespace std;
int main () {
	unsigned long long r = 1;
	for(int i=0; i<21; ++i) r*=10;
	r-= 1<<70;
	cout<<r<<endl;
	return 0;
}
