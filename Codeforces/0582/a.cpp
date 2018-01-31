#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int nums[500*500+8];

int gcd (int a, int b) {
	if(b==0) return a;	
	return gcd(b, a%b);
}

int main() {
	int n;
	cin>>n;
	
	for(int i=0; i<n*n; ++i) scanf("%d", &nums[i]);
	
	sort(nums, nums+n*n, std::greater<int>());

	priority_queue<int> throw_out;

	vector<int> a;

	a.push_back(nums[0]);
	
	for(int i=1; i<n*n; ++i) {
		while(!throw_out.empty() && throw_out.top() == nums[i]) {
			throw_out.pop();
			++i;
			if(n*n<=i) break;
		}		
		if(n*n<=i) break;		
		for(int j=0; j<a.size(); ++j) {
			int gcdi = gcd(a[j],nums[i]); 
			throw_out.push(gcdi);
			throw_out.push(gcdi);
		}
		a.push_back(nums[i]);
	}
	for(int i=0; i<a.size(); ++i) {
		cout<<a[i]<<' ';
	}
	return 0;
}
