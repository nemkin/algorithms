#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

long long a,b,m,r,c;
long long prime[500];
long long str[500][500];
long long maximum_strs[250001];

set<pair<int,int> > starting_fields;
set<pair<int,int> > area_visited;
set<long long, greater<long long>> frontier_strengths;
map<long long, set<pair<int, int> > > frontier_strength_sets;

void genPrimes() {
	int index = 0;
	bool isPrime;
	for(long long num = 2; index<500; ++num) {
		isPrime = true;
		for(long long div = 2; div<=num/2; ++div) {
			if(num%div == 0) isPrime = false;
		}
		if(isPrime) prime[index++] = num;
	} 
}

long long genStr(const int& i, const int& j) {
	return (((a%m)*(prime[i]%m))%m + ((b%m)*(prime[j]%m))%m)%m;
}

bool less(const pair<int,int>& a, const pair<int,int>& b) {
	 if(str[a.first][a.second] < str[b.first][b.second]) return true;
	 return false;
}

bool lessoreq(const pair<int,int>& a, const pair<int,int>& b) {
	 if(str[a.first][a.second] <= str[b.first][b.second]) return true;
	 return false;
}

bool inBounds(const pair<int,int>& a) {
	if(0<=a.first && a.first<r && 0<=a.second && a.second<c) return true;
	return false;
}

void genStartingFields() {
	pair<int,int> here;
	pair<int,int> up;
	pair<int,int> down;
	pair<int,int> left;
	pair<int,int> right;
	for(int i=0; i<r; ++i) for(int j=0; j<c; ++j) {
		here = make_pair(i,j);
		up = make_pair(i-1,j);
		down = make_pair(i+1,j);
		left = make_pair(i,j-1);
		right = make_pair(i,j+1);
		
		if(inBounds(up) && lessoreq(up,here) &&
		   inBounds(down) && lessoreq(down,here) &&
		   inBounds(left) && lessoreq(left,here) &&
		   inBounds(right) && lessoreq(right,here))
		   
		   starting_fields.insert(here);
		
	}
}

int main () {

	cin>>a>>b>>m>>r>>c;
	genPrimes();
	for(int i=0; i<r; ++i) for(int j=0; j<c; ++j) str[i][j] = genStr(i,j);
	for(int i=0; i<r*c+1; ++i) maximum_strs[i] = 0;
	genStartingFields();
	
	long long current_str;
	long long minimum_str;
	long long size;
	
	int x,y;
	
	pair<int,int> up;
	pair<int,int> down;
	pair<int,int> left;
	pair<int,int> right;
	
	set<pair<int, int> >::iterator current_field;
	
	for(pair<int,int> here : starting_fields) {
		cerr<<"Starting! "<<here.first<<":"<<here.second<<endl;//" ----------------------------------------"<<endl;
		
		area_visited.clear();
		
		minimum_str = -1;
		size = 0;
		
		frontier_strengths.insert(str[here.first][here.second]);
		frontier_strength_sets[str[here.first][here.second]].insert(here);
		
		while(!frontier_strengths.empty()) {
			
			current_str = *(frontier_strengths.begin());
			//cerr<<"Maximum strength in frontier: "<<current_str<<endl;
			current_field = frontier_strength_sets[current_str].begin();
			
			x = current_field->first;
			y = current_field->second;
			//cerr<<"Visiting field with maximum strength: "<<x<<":"<<y<<endl;
			
			area_visited.insert(make_pair(x,y));
			frontier_strength_sets[current_str].erase(current_field);
			if(frontier_strength_sets[current_str].empty()) frontier_strengths.erase(current_str);
			
			//cerr<<"Calculating minimum strength of currently visited area..."<<endl;
			size += 1;
			minimum_str = (minimum_str == -1) ? current_str : min(minimum_str, current_str);
			maximum_strs[size] = max(minimum_str, maximum_strs[size]);
			
			//cerr<<"Exploring new frontier..."<<endl;
			up = make_pair(x-1,y);
			down = make_pair(x+1,y);
			left = make_pair(x,y-1);
			right = make_pair(x,y+1);
			
			if(inBounds(up) && area_visited.find(up) == area_visited.end()) {
				//cerr<<"Expanding up: "<<up.first<<":"<<up.second<<endl;
				current_str = str[up.first][up.second];
				//cerr<<"Strength: "<<current_str<<endl;
				frontier_strengths.insert(current_str);
				frontier_strength_sets[current_str].insert(up);
					
			}
			
			if(inBounds(down) && area_visited.find(down) == area_visited.end()) {
				//cerr<<"Expanding down: "<<down.first<<":"<<down.second<<endl;
				current_str = str[down.first][down.second];
				//cerr<<"Strength: "<<current_str<<endl;
				frontier_strengths.insert(current_str);
				frontier_strength_sets[current_str].insert(down);
					
			}
			
			if(inBounds(left) && area_visited.find(left) == area_visited.end()) {
				//cerr<<"Expanding left: "<<left.first<<":"<<left.second<<endl;
				current_str = str[left.first][left.second];
				//cerr<<"Strength: "<<current_str<<endl;
				frontier_strengths.insert(current_str);
				frontier_strength_sets[current_str].insert(left);
					
			}
			
			if(inBounds(right) && area_visited.find(right) == area_visited.end()) {
				//cerr<<"Expanding right: "<<right.first<<":"<<right.second<<endl;
				current_str = str[right.first][right.second];
				//cerr<<"Strength: "<<current_str<<endl;
				frontier_strengths.insert(current_str);
				frontier_strength_sets[current_str].insert(right);
					
			}
			
			//cerr<<"Repeat..."<<endl<<endl<<endl;
		}
		
		//cerr<<"Finished! -----------------------------------------------------------"<<endl<<endl<<endl<<endl;

	}
	
	cerr<<"Calculating sum of maximum strengths..."<<endl;
	
	long long sum = 0;
	for(int i=2; i<=r*c; ++i) {
		sum+=maximum_strs[i];
		sum = sum%1000000007;
		cerr<<i<<". "<<maximum_strs[i]<<endl;
	}
	
	cout<<sum<<endl;

	return 0;
}
