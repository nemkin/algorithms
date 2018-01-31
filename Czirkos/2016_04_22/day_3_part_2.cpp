#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main () {
	int who = 0;
	int x[2]={0}, y[2]={0};
	char dir;
	set<pair<int,int> > visited;
	visited.insert(make_pair(0,0));

	while(cin>>dir,!cin.eof())
	{
		switch(dir) {
			case '^': ++y[who]; break;
			case '>': ++x[who]; break;
			case '<': --x[who]; break;
			case 'v': --y[who]; break;
		}
		visited.insert(make_pair(x[who],y[who]));
		who = (who+1)%2;
	}
	cout<<visited.size()<<endl;
	return 0;
}
