#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin>>t;
	for(int c=1; c<=t; ++c) {

		int n;
		cin>>n;
		int thefriend[n];
		for(int i=0; i<n; ++i) 
		{
			cin>>thefriend[i];
			--thefriend[i];
		}
		
		bool good;
		int thesize = 0;
		int maxsize = 0;
		for(int i=0; i<(1<<n); ++i) {
			good = true;
			for(int j=0; j<10; ++j) {
				if((i%(1<<j)) == 1 && !(i%(1<<thefriend[j])) == 0) 
					{
						good = false;
						break;
					}

			}
			if(good){
			cout<<i<<endl;
			thesize = 0;
			for(int j=0; j<10; ++j) if(i%(1<<j)) ++thesize;
			if(thesize>maxsize) maxsize = thesize;
			}


		}
		cout<<"Case #"<<c<<": "<<maxsize<<endl;
	} 

	return 0;
}
