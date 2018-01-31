#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main () {
	int x=0, y=0;
	char dir;
	set<pair<int,int> > visited;
	visited.insert(make_pair(x,y));
	
	while(cin>>dir,!cin.eof())
	{
		switch(dir) {
			case '^': ++y; break;
			case '>': ++x; break;
			case '<': --x; break;
			case 'v': --y; break;
		}
		visited.insert(make_pair(x,y));
	}

	cout<<visited.size()<<endl;
	return 0;
}
