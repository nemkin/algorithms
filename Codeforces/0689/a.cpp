#include <iostream>
using namespace std;
int main () {
	bool n[10] = {false};
	bool oszlop[3] = {false};
	bool sor[3] = {false};
	int db;
	string num;
	cin>>db>>num;
	
	for(int i=0; i<db; ++i) {
		int thenum = num[i]-'0';
		n[thenum] = true;
		if(thenum==0) continue;
		--thenum;
		sor[(thenum/3)] = true;
		oszlop[(thenum%3)] = true;
		
	}

	if(n[0]) {
		if (n[1] || n[2] || n[3])	{
			cout<<"YES"<<endl;
			return 0;
		} else {
			cout<<"NO"<<endl;
			return 0;
		}
	} else {
		if(sor[0] && sor[2] && oszlop[0] && oszlop[2]) {
			if(!n[7] && !n[9] && n[8]) {
				cout<<"NO"<<endl;
				return 0;
			} else {
				cout<<"YES"<<endl;
				return 0;
			}
		} else {
			cout<<"NO"<<endl;
			return 0;
		}	
	}

	return 0;

}
