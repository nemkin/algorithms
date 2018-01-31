#include <iostream>
#include <cstdio>
using namespace std;
int main () {
	int count = 0;
	string answ;
	int primes[] = {2,4,3,9,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47};
	for(int i=0; i<19; ++i) {
		cout<<primes[i]<<endl;
		fflush(stdout);
		cin>>answ;
		if(answ=="yes") ++count;
		if(1<count) { cout<<"composite"<<endl; fflush(stdout); return 0;}
	}
	cout<<"prime"<<endl;
	fflush(stdout);
	return 0;
}
