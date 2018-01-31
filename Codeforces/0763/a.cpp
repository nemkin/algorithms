#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int n;
	cin>>n;
	int e[n-1][2];
	int c[n];
	for(int i=0; i<n-1; ++i) cin>>e[i][0]>>e[i][1];
	for(int i=0; i<n; ++i) cin>>c[i];

	set<int> indexes;
	for(int i=0; i<n-1; ++i) {
		if(c[e[i][0]-1] != c[e[i][1]-1]) {
			indexes.insert(i);
		}
	}

	if(indexes.empty()) {
		cout<<"YES\n1"<<endl;
		return 0;
	}
	
	map<int,int> db;

	for(auto i : indexes) {
		++db[e[i][0]];
		++db[e[i][1]];
	}	

	for(auto pair : db) {
		if(pair.second == indexes.size()) {
			cout<<"YES\n"<<pair.first<<endl;
			return 0;
		}
	}

	cout<<"NO"<<endl;
	return 0;
}
