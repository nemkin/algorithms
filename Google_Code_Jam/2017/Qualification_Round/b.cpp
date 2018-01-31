#include <iostream>
#include <string>

using namespace std;

bool tidy (long long num) {
	string snum = to_string(num);
	for(int i=0; i<snum.length()-1; ++i) {
		if(snum[i] > snum[i+1]) return false;
	}
	return true;
}

int main() {
	int t;
	cin>>t;

	for(int c=0; c<t; ++c) {	

		long long num;
		cin>>num;

		while(!tidy(num)) --num;

		cout<<"Case #"<<c+1<<": "<<num<<endl;	

	}
	
	return 0;
}
