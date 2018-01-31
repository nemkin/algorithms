#include <iostream>
#include <string>
using namespace std;
int main() {
	
	int place;
	cin>>place;
	
	int i=0;
	int num=1;
	
	while(true) {
		string numstr = to_string(num);
		for(int j=1; j<=numstr.length(); ++j) {
			++i;
			if(i==place) { cout<<numstr[j-1]<<endl; return 0;}
		}
		
		++num;
	}
	
	
	return 0;
}
