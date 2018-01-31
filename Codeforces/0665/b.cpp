#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> items;
	items.resize(k);
	for(int i=0; i<k; ++i) cin>>items[i];
	int item;
	vector<int>::iterator it;
	int index;
	int sum = 0;
	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
		cin>>item;
		it = find(items.begin(), items.end(), item);
		index = distance(items.begin(),it);
		items.erase(it);
		items.insert(items.begin(), item);
		sum+=index+1;
	}
	cout<<sum<<endl;
	return 0;
}
