#include <iostream>
using namespace std;

bool isLeap(int year) {
	return (year%4 == 0 && year%100!=0 || year%400 == 0);
}

int main () {
	int year;
	bool leap;
	cin>>year;
	leap = isLeap(year);
	
	int addedDays = 0;
	for(int result = year+1; ; ++result) {
		if(isLeap(result)) addedDays+=2;
		else addedDays+=1;

		if(leap == isLeap(result) && addedDays%7 == 0) {
			cout<<result<<endl;
			break;
		}
	}	

	return 0;
}
