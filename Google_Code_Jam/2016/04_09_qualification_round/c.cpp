#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long n, j;


unsigned long long remainder_of_first_digit(unsigned long long base, unsigned long long divisor) {
	unsigned long long remainder = 1;
	for(int i=1; i<=(n-1); ++i)  {
		remainder*=base;
		remainder = remainder%divisor;
	}
	return remainder;
	
}

unsigned long long divisor (unsigned long long num, unsigned long long base) {
	for(unsigned long long i=2; i<=10000; ++i) {
		if((num+remainder_of_first_digit(base,i))%i == 0) return i;
	}
	return -1;
}


string to_binstring (unsigned long long num) {
	string binary = "";
	for(unsigned long long i=0; i<n; ++i) {
		if(num%2) binary+='1';
		else binary+='0';
		num = num>>1;
	}
	reverse(binary.begin(), binary.end());
	return binary;	
}

int main () {
	cin>>n;
	cin>>n;
	cin>>j;
	unsigned long long top = 1;
	top = top<<(n-1);
	unsigned long long start = 1;
	string curr;
	unsigned long long num;
	unsigned long long div;
	bool prime;
	size_t unused=0;
	string currline;
	unsigned long long written = 0;
	cout<<"Case #1:"<<endl;
	for(unsigned long long i=start; i<top; i+=2) {
		curr = to_binstring(i);
		curr[0] = '1';
		currline += curr;
		curr[0] = '0';
		bool prime = false;
		for(int base = 2; base<=10; ++base) {
			num = stoull(curr,&unused,base);
			div = divisor(num,base);
			if(div == -1) prime = true;
			currline+=' ';
			currline+=to_string(div); 
		}
		if(!prime) {
			cout<<currline<<endl;
			++written;
			if(written==j) return 0;
		}
		currline = "";
	}
	return 0;
}
