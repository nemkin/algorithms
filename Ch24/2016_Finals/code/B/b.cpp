#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

long long a,b,m,r,c;
long long prime[500];
long long str[500][500];

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
		//cerr<<i<<":"<<j<<"-----------------------------------"<<endl;
		frontier.clear();
		visited.clear();
		minStr=-1;
		size=0;
		frontier.insert(make_pair(i,j));
		while(!frontier.empty()) {
			//cerr<<"Frontier contains: ";
			//for(auto& fronty : frontier) cerr<<fronty.first<<":"<<fronty.second<<" ";	
			curr = max_element(frontier.begin(), frontier.end(), cmp);
			x = curr->first;
			y = curr->second;

			//cerr<<"Maximum on frontier: "<<x<<":"<<y<<endl;

			visited.insert(*curr);
			frontier.erase(curr);
			minStr = minStr == -1 ? str[x][y] : min(minStr, str[x][y]);
			++size;
			//cerr<<"MinStr: "<<minStr<<" Size: "<<size<<endl;
			maxStrs[size] = max(maxStrs[size], minStr);

			up = make_pair(x-1,y);
			down = make_pair(x+1,y);
			left = make_pair(x,y-1);
			right = make_pair(x,y+1);

			if(inBounds(up) && visited.find(up) == visited.end()) {
				frontier.insert(up);
				//cerr<<"Up expanded: "<<up.first<<":"<<up.second<<endl;
			}

			if(inBounds(down) && visited.find(down) == visited.end()) {
				frontier.insert(down);
				//cerr<<"Down expanded: "<<down.first<<":"<<down.second<<endl;
			}

			if(inBounds(left) && visited.find(left) == visited.end()) {
				frontier.insert(left);
				//cerr<<"Left expanded: "<<left.first<<":"<<left.second<<endl;
			}

			if(inBounds(right) && visited.find(right) == visited.end()) {
				frontier.insert(right);
				//cerr<<"Right expanded: "<<right.first<<":"<<right.second<<endl;
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
