#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct shiftmatrix {
	int n, m;
	vector<vector<int> > matrix;

	shiftmatrix(int n, int m):n(n),m(m) {
		matrix.resize(n);
		for(int i=0; i<n; ++i) { matrix[i].resize(m); for(int j=0; j<m; ++j) {
			matrix[i][j] = 0;
		}} 
	}


	void shiftcolumndown (int c) {
		int tmp = matrix[n-1][c];
		for(int i=n-2; 0<=i; --i) {
			matrix[i+1][c] = matrix[i][c];
		}
		matrix[0][c] = tmp;
	}

	void shiftrowright (int r) {
		int tmp = matrix[r][m-1];
		for(int j=m-2; 0<=j; --j) {
			matrix[r][j+1] = matrix[r][j];
		}
		matrix[r][0] = tmp;
	}
};

int main () {
	int n, m, q;
	cin>>n>>m>>q;
	string tmp;
	getline(cin,tmp);

	shiftmatrix matrix(n,m);
	
	string lines[q];
	
	for(int line=0; line<q; ++line) getline(cin, lines[line]);
	
	int op;
	int col;
	int row;
	int num;
	stringstream stream;
	for(int line=q-1; 0<=line; --line) {
		stream<<lines[line];
		
		stream>>op;
		switch(op) {
			case 1:
				stream>>row;
				--row;
				matrix.shiftrowright(row);	
			break;
			case 2:
				stream>>col;
				--col;
			matrix.shiftcolumndown(col);	

			break;
			case 3:
				stream>>row>>col>>num;
				--row;
				--col;
				matrix.matrix[row][col] = num; 
			break;
		}
		stream.clear();
	}

	for(int i=0; i<n; ++i) { for(int j=0; j<m; ++j) { cout<<matrix.matrix[i][j]<<' '; } cout<<endl; }

	return 0;
}
