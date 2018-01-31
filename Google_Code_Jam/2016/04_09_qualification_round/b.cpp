#include <iostream>
#include <string>

using namespace std;

bool allplus (string a) {
	for(int i=0; i<a.length(); ++i) if(a[i]!='+') return false;
	return true;
}

void flip (string& a) {
	if(a[0] == '+') {
		int i=0;
		while(a[i] == '+') a[i++] = '-';
	} else {
		int until=a.length()-1;
		while(a[until]=='+') --until;
		for(int i=0; i<=until; ++i) {
			if(a[i] == '+') a[i] = '-';
			else a[i] = '+';
		}   
	}
}

int main () {
	int n;
	cin>>n;
	string cases[n];
	for(int i=0; i<n; ++i) cin>>cases[i];
	
	for(int i=0; i<n; ++i) {
		int flips = 0;
		while(!allplus(cases[i])) {
			flip(cases[i]);
			++flips;
		}
		cout<<"Case #"<<i+1<<": "<<flips<<endl;
	}

	return 0;
}
