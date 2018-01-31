#include <iostream>
#include <map>
using namespace std;
int main() {
	map<char, char> pairs;
	pairs.insert(make_pair('A','A'));
	pairs.insert(make_pair('d','b'));
	pairs.insert(make_pair('b','d'));
	pairs.insert(make_pair('H','H'));
	pairs.insert(make_pair('I','I'));
	pairs.insert(make_pair('M','M'));
	pairs.insert(make_pair('O','O'));
	pairs.insert(make_pair('o','o'));
	pairs.insert(make_pair('p','q'));
	pairs.insert(make_pair('q','p'));
	pairs.insert(make_pair('T','T'));
	pairs.insert(make_pair('U','U'));
	pairs.insert(make_pair('V','V'));
	pairs.insert(make_pair('v','v'));
	pairs.insert(make_pair('W','W'));
	pairs.insert(make_pair('w','w'));
	pairs.insert(make_pair('X','X'));
	pairs.insert(make_pair('x','x'));
	pairs.insert(make_pair('Y','Y'));

	string a;
	cin>>a;

	int j;
	for(int i=0; i<a.length(); ++i) {
		j=a.length()-1-i;
		if(pairs[a[i]] != a[j]) {
			cout<<"NIE";
			return 0;
		}
	}

	cout<<"TAK";
	return 0;
}
