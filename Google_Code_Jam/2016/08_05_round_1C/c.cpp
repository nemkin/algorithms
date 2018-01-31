#include <iostream>
#include <sstream>
using namespace std;
int main () {
	int cases;
	cin>>cases;
for(int cc=1; cc<=cases; ++cc) {
	
	cout<<"Case #"<<cc<<": ";
	
	int j,p,s,k;
	cin>>j>>p>>s>>k;
	
	int jpnums[j][p];
	int jsnums[j][s];
	int psnums[p][s];
	
	for(int ji=0; ji<j; ++ji) for(int pi=0; pi<p; ++pi) for(int si=0; si<s; ++si) {
			jpnums[ji][pi]=0;
			jsnums[ji][si]=0;
			psnums[pi][si]=0;
	}
	
	stringstream ss;
	int nums = 0;
	for(int ji=0; ji<j; ++ji) for(int pi=0; pi<p; ++pi) for(int si=0; si<s; ++si) {
		if(jpnums[ji][pi]<k && jsnums[ji][si]<k && psnums[pi][si]<k) {
			++nums;
			ss<<ji+1<<' '<<pi+1<<' '<<si+1<<endl;
			++jpnums[ji][pi];
			++jsnums[ji][si];
			++psnums[pi][si];
		}
	
	}
	cout<<nums<<endl;
	cout<<ss.str();
	
}
	return 0;
}
