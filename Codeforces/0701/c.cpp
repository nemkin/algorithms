#include <iostream>
#include <map>

using namespace std;

int main () {	
	int n;
	string locpok;
	cin>>n>>locpok;

	if(n==1) {
		cout<<1<<endl;
		return 0;
	}

	map<char, int> collector;

	for(int i=0; i<n; ++i) {
		collector[locpok[i]] = 0;
	}

	int zeros = collector.size()-1;

	int first = 0;
	int last = 0;
	collector[locpok[0]] = 1;
	
	int minlength = -1;
	
	while(true) {

		if(first<last && 1<collector[locpok[first]]) {
			--collector[locpok[first]];
			++first;
		} else if(last<n-1) {
			++last;
			if(collector[locpok[last]] == 0) --zeros;
			++collector[locpok[last]];
		} else {
			break;
		}

		if(zeros == 0) {
			if(minlength == -1) minlength = last-first+1;
			else {
				if((last-first+1)<minlength) minlength = last-first+1;
			}
		}

	}	
	cout<<minlength<<endl;
	return 0;
}
