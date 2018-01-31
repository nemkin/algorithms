#include <iostream>
#include <string>
using namespace std;
int main () {
	int n;
	cin>>n;
	int cases[n];
	for(int i=0; i<n; ++i) {
		cin>>cases[i];
	}
	int current;
	string currstr;
	bool seen[10];
	bool seenall;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<10; ++j) seen[j] = false;
		for(int times=1; times<=1000000; times++) {
			current = cases[i]*times;
			currstr = std::to_string(current);
			for(int k=0; k<currstr.length(); ++k) {
				seen[currstr[k]-'0'] = true;
			}
			seenall = true;
			for(int l=0; l<10; ++l) seenall = seenall && seen[l];
			if(seenall) {
				cout<<"Case #"<<i+1<<": "<<current<<endl;
				break;
			}
		}
		if(!seenall) cout<<"Case #"<<i+1<<": "<<"INSOMNIA"<<endl;		
	}
}
