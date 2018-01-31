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
	
	int mindist = -1;

	do {
		dist = 0;
		string prev = cityvec[0];
		string curr;
		for(int i=1; i<cityvec.size(); ++i) {
			curr = cityvec[i];
			dist+=distances[make_pair(prev,curr)];
			prev = curr;
		}
		
		mindist = (mindist == -1) ? dist : min(mindist,dist); 

	} while(next_permutation(cityvec.begin(), cityvec.end()));
	
	cout<<mindist<<endl;

	return 0;
}
