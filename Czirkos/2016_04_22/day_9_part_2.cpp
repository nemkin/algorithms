#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

int main() {

	stringstream ss;
	vector<string> cityvec;
	set<string> citynames;
	map<pair<string,string>, int> distances;

	string line;	
	string cityfrom, cityto;
	string to, eq;
	int dist;

	while(getline(cin,line))
	{
		ss<<line;
		ss>>cityfrom>>to>>cityto>>eq>>dist;
		ss.clear();
	
		distances[make_pair(cityfrom, cityto)] = dist;
		distances[make_pair(cityto, cityfrom)] = dist;

		citynames.insert(cityfrom);
		citynames.insert(cityto);
	}
	
	copy(citynames.begin(), citynames.end(), back_inserter(cityvec));	
	
	int maxdist = -1;

	do {
		dist = 0;
		for(int i=1; i<cityvec.size(); ++i) dist+=distances[make_pair(cityvec[i-1],cityvec[i])];
		maxdist = (maxdist == -1) ? dist : max(maxdist,dist); 

	} while(next_permutation(cityvec.begin(), cityvec.end()));
	
	cout<<maxdist<<endl;

	return 0;
}
