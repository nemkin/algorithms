#include <iostream>
using namespace std;
int main () {
	int n;
	cin>>n;
	for(int j=0; j<n; ++j) {
		string s;
		cin>>s;
		
		string output = "";
		output += s[0];

		for(int i=1; i<s.length(); ++i) {
			if(output[0]<=s[i]) output = s[i] + output;
			else output = output + s[i];
		}
		cout<<"Case #"<<j+1<<": "<<output<<endl;

	}
	return 0;
}
