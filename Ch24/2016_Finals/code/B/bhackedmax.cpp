#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

long long a,b,m,r,c;
long long prime[500];
long long str[500][500];
map<long long, set<pair<int,int>>> frontierStrengthSets;

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

long long genStr(int i, int j) {
	return (((a%m)*(prime[i]%m))%m + ((b%m)*(prime[j]%m))%m)%m;
}

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if(str[a.first][a.second] < str[b.first][b.second]) return true;
	return false;
}

bool lessoreq(const pair<int,int>& a, const pair<int,int>& b) {
	if(str[a.first][a.second] <= str[b.first][b.second]) return true;
	return false;
}

bool inBounds(pair<int,int> a) {
	if(0<=a.first && a.first<r && 0<=a.second && a.second<c) return true;
	return false;
}

int main () {
	cin>>a>>b>>m>>r>>c;
	genPrimes();
	for(int i=0; i<r; ++i) for(int j=0; j<c; ++j) str[i][j] = genStr(i,j);
	//for(int i=0; i<r; ++i) {
	//	for(int j=0; j<c; ++j) {
	//		cerr<<str[i][j]<<' ';
	//	}
	//	cerr<<endl;
	//}

	long long maxStrs[r*c+1];
	for(int i=0; i<r*c+1; ++i) maxStrs[i] = 0;
	set<pair<int,int> > toTest;
	set<pair<int,int> > frontier;
	set<pair<int,int> > visited;
	set<pair<int,int> >::iterator curr;
	int x, y;
	pair<int,int> here;
	pair<int,int> up;
	pair<int,int> down;
	pair<int,int> left;
	pair<int,int> right;

	long long minStr;
	int size;


	set<int, std::greater<int>> frontierStrengths;

	for(int i=0; i<r; ++i) for(int j=0; j<c; ++j) {
		here = make_pair(i,j);
		up = make_pair(i-1,j);
		down = make_pair(i+1,j);
		left = make_pair(i,j-1);
		right = make_pair(i,j+1);

		if(inBounds(up) && lessoreq(up,here)) 
		if(inBounds(down) && lessoreq(down,here)) 
		if(inBounds(left) && lessoreq(left,here)) 
		if(inBounds(right) && lessoreq(right,here)) 
		
		toTest.insert(here);
		
	}
	int i,j;
	for(auto& placeToTest : toTest) { i = placeToTest.first; j=placeToTest.second;
		cerr<<i<<":"<<j<<"-----------------------------------"<<endl;
		frontier.clear();
		visited.clear();
		minStr=-1;
		size=0;
		frontier.insert(make_pair(i,j));
		frontierStrengths.insert(str[i][j]);
		frontierStrengthSets[str[i][j]].insert(make_pair(i,j));
		while(!frontier.empty()) {
			cerr<<"Frontier size: "<<frontier.size()<<endl;
			cerr<<"Frontier contains: ";
			int salala = 0;
			set<pair<int,int>>::iterator frontierend = frontier.end();
			for(set<pair<int,int>>::iterator it = frontier.begin(); it!=frontierend; it++) {
				 cerr<<it->first<<":"<<it->second<<" ";
			}
			curr = frontierStrengthSets[*frontierStrengths.begin()].begin();
			x = curr->first;
			y = curr->second;

			cerr<<"Maximum on frontier: "<<x<<":"<<y<<endl;

			visited.insert(*curr);
			frontierStrengthSets[str[x][y]].erase(frontierStrengthSets[str[x][y]].find(*curr));
			if(frontierStrengthSets[str[x][y]].size() == 0) frontierStrengths.erase(frontierStrengths.find(str[x][y]));
			frontier.erase(curr);
			minStr = minStr == -1 ? str[x][y] : min(minStr, str[x][y]);
			++size;
			cerr<<"MinStr: "<<minStr<<" Size: "<<size<<endl;
			maxStrs[size] = max(maxStrs[size], minStr);

			up = make_pair(x-1,y);
			down = make_pair(x+1,y);
			left = make_pair(x,y-1);
			right = make_pair(x,y+1);

			if(inBounds(up) && visited.find(up) == visited.end()) {
				frontier.insert(up);
				frontierStrengths.insert(str[up.first][up.second]);
				frontierStrengthSets[str[up.first][up.second]].insert(up);
				cerr<<"Up expanded: "<<up.first<<":"<<up.second<<endl;
			}cerr<<"Frontier size: "<<frontier.size()<<endl;
			cerr<<"Frontier contains: ";
			salala = 0;
			frontierend = frontier.end();
			for(set<pair<int,int>>::iterator it = frontier.begin(); it!=frontierend; it++) {
				 cerr<<it->first<<":"<<it->second<<" ";
}

			if(inBounds(down) && visited.find(down) == visited.end()) {
				frontier.insert(down);
				frontierStrengths.insert(str[down.first][down.second]);
				frontierStrengthSets[str[down.first][down.second]].insert(down);

				cerr<<"Down expanded: "<<down.first<<":"<<down.second<<endl;
			}cerr<<"Frontier size: "<<frontier.size()<<endl;
			cerr<<"Frontier contains: ";
			salala = 0;
			frontierend = frontier.end();
			for(set<pair<int,int>>::iterator it = frontier.begin(); it!=frontierend; it++) {
				 cerr<<it->first<<":"<<it->second<<" ";
			}

			if(inBounds(left) && visited.find(left) == visited.end()) {
				frontier.insert(left);
				frontierStrengths.insert(str[left.first][left.second]);
				frontierStrengthSets[str[left.first][left.second]].insert(left);

				cerr<<"Left expanded: "<<left.first<<":"<<left.second<<endl;
			}cerr<<"Frontier size: "<<frontier.size()<<endl;
			cerr<<"Frontier contains: ";
			salala = 0;
			frontierend = frontier.end();
			for(set<pair<int,int>>::iterator it = frontier.begin(); it!=frontierend; it++) {
				 cerr<<it->first<<":"<<it->second<<" ";
			}

			if(inBounds(right) && visited.find(right) == visited.end()) {
				frontier.insert(right);
				frontierStrengths.insert(str[right.first][right.second]);
				frontierStrengthSets[str[right.first][right.second]].insert(right);

				cerr<<"Right expanded: "<<right.first<<":"<<right.second<<endl;
			}cerr<<"Frontier size: "<<frontier.size()<<endl;
			cerr<<"Frontier contains: ";
			salala = 0;
			frontierend = frontier.end();
			for(set<pair<int,int>>::iterator it = frontier.begin(); it!=frontierend; it++) {
				 cerr<<it->first<<":"<<it->second<<" ";
			}

		}
	}
	long long sum = 0;
	for(int i=2; i<=r*c; ++i) {
		sum+=maxStrs[i];
		sum = sum%1000000007;
		cerr<<i<<". "<<maxStrs[i]<<endl;
	}

	cout<<sum<<endl;

	return 0;
}
