#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

string t[60];
int r,n;

void print() {
	
	cout<<"..........."<<endl;
	for (int i = 0; i < r; i++){
		cout<<t[i]<<endl;
	}
	cout<<"..........."<<endl;
	for (int i = 0; i < r; i++){
		cout<<t[i+r]<<endl;
	}
	cout<<"..........."<<endl;
	 
	
}

int min(int a, int b, int c) {
	
	return min(min(a,b),c);
}

int main() {
	
	cin>>r>>n;
	r=r/2;
	
	string tmp;
	cin>>tmp;
	for (int i = 0; i < r; i++){
		cin>>t[i];
	}
	cin>>tmp;
	for (int i = 0; i < r; i++){
		cin>>t[r+i];
	}
	cin>>tmp;
	
	//print();
	
	int leftsum=0, rightsum=0;
	for (int i = 0; i < 2*r; i++){
		if (t[i][0] == '#') leftsum++;
		if (t[i][1] == '#') leftsum++;
		if (t[i][2] == '#') leftsum++;
		if (t[i][4] == '#') leftsum++;
		
		if (t[i][6] == '#') rightsum++;
		if (t[i][8] == '#') rightsum++;
		if (t[i][9] == '#') rightsum++;
		if (t[i][10] == '#') rightsum++;
	}
	
	
	for (int num=0; num<n; num++) {
		
		//print();
		//cout<<endl<<endl;
		
		int free[60];
		for (int i=0; i<2*r; i++) {
			free[i]=0;
			for (int j = 0; j < 11; j++) {
				if (t[i][j] == '-'){
					free[i]++;
				}
				
			}
		}
		vector<int> lehet;
		if (free[0] > 0 || free[r] > 0) {
			lehet.push_back(0);
			lehet.push_back(r);
		}
		else {
			for (int i = 0; i < 2*r; i++){
				lehet.push_back(i);
			}
		}
		
		//cout<<"Lehet hossza: "<< lehet.size()<<endl;
		//cout<<leftsum<<" "<<rightsum<<endl;
		
		int row = 0;
		for (int i : lehet) {
			if (free[i] > free[row])
				row = i;
			else if (free[i] == free[row]) {
				int d1, d2;
				if (i<r)
					d1 = min(i+1, r-i);
				else
					d1=min(i+1-r, 2*r-i);
				if (row<r)
					d2 = min(row+1, r-row);
				else
					d2=min(row+1-r, 2*r-row);
				
				//cout<<"D1D2  "<<i<<" "<<row<<" "<<d1<<d2<<endl;
				if (d1 < d2)
					row = i;
			}
		}
		
		if (t[row][4] == '-' && (leftsum <= rightsum || t[row][6] != '-')) {
			t[row][4] = ('a'+num);
			leftsum++;
			continue;
		}
		if (t[row][6] == '-') {
			t[row][6] = ('a'+num);
			rightsum++;
			continue;
		}
		if (t[row][2] == '-' && (leftsum <= rightsum || t[row][8] != '-')) {
			t[row][2] = ('a'+num);
			leftsum++;
			continue;
		}
		if (t[row][8] == '-') {
			t[row][8] = ('a'+num);
			rightsum++;
			continue;
		}
		if (t[row][0] == '-' && (leftsum <= rightsum || t[row][10] != '-')) {
			t[row][0] = ('a'+num);
			leftsum++;
			continue;
		}
		if (t[row][10] == '-') {
			t[row][10] = ('a'+num);
			rightsum++;
			continue;
		}
		if (t[row][5] == '-') {
			t[row][5] = ('a'+num);
			continue;
		}
		if (t[row][1] == '-' && (leftsum <= rightsum || t[row][9] != '-')) {
			t[row][1] = ('a'+num);
			leftsum++;
			continue;
		}
		if (t[row][9] == '-') {
			t[row][9] = ('a'+num);
			rightsum++;
			continue;
		}
		
	}
	
	print();
	
	return 0;
}

