#include <iostream>
using namespace std;
int main() {

	int t;
	cin>>t;
	
	string eset;
	int k;
	for(int i=0; i<t; ++i) {
		cin>>eset;
		cin>>k;
		int flips = 0;
		int j;
		for(j=0; j<(eset.length()-k+1); ++j) {
			
			if(eset[j] == '-') {
				++flips;
				for(int l=0; l<k; ++l) {
					if(eset[j+l] == '-') eset[j+l] = '+';
					else eset[j+l] = '-';
				}
				
			}
			
		}
		bool cando = true;
		for(; j<eset.length(); ++j) {
			if(eset[j] == '-') cando = false;
		}		
		

		cout<<"Case #"<<i+1<<": ";
		if(cando) {
			cout<<flips<<endl;
		} else {
			cout<<"IMPOSSIBLE"<<endl;
		}
	}

	return 0;
}
