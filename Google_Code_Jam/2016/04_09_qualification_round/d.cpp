#include <iostream>
#include <string>
using namespace std;
int main () {
	int numofcases;
	cin>>numofcases;
	long long k, c, s;
	for(int i=1; i<=numofcases; ++i) {
		cout<<"Case #"<<i<<": ";
		cin>>k>>c>>s;

		long long tilecount = 0;
		string tileplaces = "";
		
		long long steps = 0;
		long long index = 0;

		for(long long i=0; i<k; ++i) {
			index*=k;
			index+=i;
			++steps;

			if(steps==c) {
				++tilecount;
				tileplaces+=to_string(index+1);
				tileplaces+=' ';

				steps=0;
				index=0;
			}

		}

		if(steps!=0) {
			++tilecount;
			tileplaces+=to_string(index+1);
			tileplaces+=' ';
			
			steps=0;
			index=0;
		}
		
		if(tilecount<=s) cout<<tileplaces<<endl;
		else cout<<"IMPOSSIBLE"<<endl;

	}

	return 0;
}
