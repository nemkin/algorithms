#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

multiset<int, greater<int> > nums;
vector<int> a;
int gcd (int a, int b) {
	if(b==0) return a;	
	return gcd(b, a%b);
}

int main() {
	int n;
	cin>>n;

	int tmp;
	for(int i=0; i<n*n; ++i) {
		scanf("%d", &tmp);
		nums.insert(tmp);
	}

	while(!nums.empty()) {
		for(int j=0; j<a.size(); ++j) {
			int gcdi = gcd(a[j],*nums.begin()); 
			nums.erase(nums.find(gcdi));
			nums.erase(nums.find(gcdi));
		}
		a.push_back(*nums.begin());
		nums.erase(nums.begin());
	}
	for(int i=0; i<a.size(); ++i) {
		cout<<a[i]<<' ';
	}
	return 0;
}
