#include <iostream>
using namespace std;
int main () {
	int n;
	cin>>n;
	cout<<(n+(n%2))*(n+(n%2)-2)/8<<endl;
	return 0;
}
