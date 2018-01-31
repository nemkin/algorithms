#include <iostream>
using namespace std;
int main() {

	int t;
	cin>>t; 
	for(int i=1; i<=t; ++i) {
		long long hd, ad, hk, ak, b, d;
		cin>>hd>>ad>>hk>>ak>>b>>d;
		cout<<hd<<ad<<hk<<ak<<b<<d;	
		cout<<"Case #"<<i<<": ";
		if(hd <= hk-ad) 
		{
			if(b>0) { 
			long long time;
			long long bebuffed = hk-ad;
			if((bebuffed % b) == 0) time = bebuffed/b;
			else time = bebuffed/b + 1;
			cout<< time+1<<endl;}
			else {
				cout<<hk/ad+((hk%ad)==0 ? 0 : 1)<<endl;
			}
		} else cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
