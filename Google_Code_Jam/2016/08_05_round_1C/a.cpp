#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int cases;
	cin>>cases;
	for(int ccase = 1; ccase<=cases; ++ccase) {
		int n;
		cin>>n;
		int nums[n];
		int sums = 0;
		for(int i=0; i<n; ++i) {
			cin>>nums[i];
			sums+=nums[i];
		}

		cout<<"Case #"<<ccase<<": ";

		int curr, maxe;

		while(0<sums) {

			curr = max_element(nums, nums+n)-nums;
			--nums[curr];
			--sums;
			maxe = max_element(nums, nums+n)-nums;

			cout<<(char)('A' + curr);
			if(nums[maxe]<=(sums-nums[maxe])) cout<<' ';

		}
		cout<<endl;
	} 

	return 0;
}
