#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int i, v;
} elem;

bool cmp (elem a, elem b) {
	if(a.v<b.v) return true;
	return false;
}

int main() {
	int n;
	cin>>n;
	elem a[n];
	for(int i=0; i<n; ++i) {
		cin>>a[i].v;
		a[i].i = i+1;
	}
	sort(a, a+n, cmp);
	
	for(int i=0; i<n/2; ++i) {
		cout<<a[i].i<<' '<<a[n-1-i].i<<endl;
	}
	
	return 0;
}
