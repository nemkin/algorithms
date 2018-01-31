#include <iostream>
#include <string>
using namespace std;
int main () {
	string number;
	int shift;
	getline(cin, number, 'e');
	cin>>shift;

	number.erase(1,1);
	string result;
	string tmp;
	if(number.size()<shift+1) {
		tmp = string(shift+1-number.size(),'0');
		result=number;
	} else if (number.size() == shift+1) {
		result = number;
	} else {
		number.insert(shift+1, ".");
		result = number;
	}	
	int first=0, last=result.size()-1;
	while(first<result.size() && result[first] == '0') ++first;
	if(tmp.size()==0) while(first<=last && result[last] == '0') --last;
	if(last<first) {cout<<'0'<<endl; return 0;}
	if(first==last && result[first]=='.') {
		cout<<'0'<<endl;
		return 0;
	}
	if(result[first] == '.') --first;
	if(result[last]== '.') --last;
	cout<<result.substr(first,last-first+1)+tmp<<endl;
	
	return 0;
}
