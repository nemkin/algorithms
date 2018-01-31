#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int t;
	cin>>t;
	cout<<setprecision(9);
	for(int c=1; c<=t; ++c) {

		int d, n;
		cin>>d>>n;
		int ki,si;
		double maxmikoreroda = 0, mikoreroda;
		for(int i=0; i<n; ++i) {
			cin>>ki>>si;
			
			mikoreroda = (d-ki)/(double)si;
		        if(mikoreroda>maxmikoreroda) maxmikoreroda=mikoreroda;	
		}
		cout<<"Case #"<<c<<": "<<d/maxmikoreroda<<endl;
	}

	return 0;
}
