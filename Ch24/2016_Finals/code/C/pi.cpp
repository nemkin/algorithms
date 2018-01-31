#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
long long szamrendszer;

string leading (long long number) {
	if(number<1) return "";
	string ret = leading(number/szamrendszer);
	ret = (char)((number%szamrendszer)+'0') + ret;
	return ret;
}

int main() {
	cin>>szamrendszer;
	double pi = M_PI;	
	cout<<leading(3)<<',';
	for(int i=0; i<200; ++i) {
		pi -= (long long)pi;
		pi*=szamrendszer;
		cout<<(long long) pi;
	}
	return 0;
}
