#include <iostream>
#include <cmath>
using namespace std;
typedef struct cell {
	bool isWall;
	bool isDiamond;
	int result;
} cell;

int main () {

	int size, numofd, numofw;
	cin>>size>>numofd;
	cell cells[2*size][size];

	for(int i=0; i<2*size; ++i) for(int j=0; j<size; ++j) {
		cells[i][j].isDiamond = false;
		cells[i][j].isWall = false;
		cells[i][j].result = -1;
	}

	cells[0][0].result = 0;

	int col, row, fromrow, torow;
	char tmp;
	for(int i=0; i<numofd; ++i) {
		cin>>col;
		cin>>tmp;
		cin>>row;
		cells[col][row].isDiamond = true;
	}

	cin>>numofw;
	for(int i=0; i<numofw; ++i) {
		cin>>col;
		cin>>tmp;
		cin>>fromrow;
		cin>>tmp;
		cin>>torow;
		for(int j=fromrow; j<=torow; ++j) cells[col][j].isWall=true;
	}



	int brow, bcol;
	int maxcol = 2*(size-1);
	int maxrow = 0;
	int bmaxrow = 0;
	for(col = 1; col<=maxcol; ++col) {
		bmaxrow=maxrow;
		maxrow = min(col, maxcol-col);
		for(row=0; row<=maxrow; ++row) {
			if(cells[col][row].isWall) {
				cells[col][row].result = -1;
				continue;
			}

			brow = row;
			bcol = col-1;

			if(0<=brow && brow<=bmaxrow && 0<=bcol && bcol<=maxcol) {
				cells[col][row].result = cells[bcol][brow].result;
			}

			if(size-1<col) {
				brow = row+1;
			} else {
				brow = row-1;
			}

			if(0<=brow && brow<=bmaxrow && 0<=bcol && bcol<=maxcol) {
				cells[col][row].result = max(cells[col][row].result, cells[bcol][brow].result);
			}

			if(cells[col][row].isDiamond && cells[col][row].result!=-1) cells[col][row].result++;		
		}
	}

	cout<<cells[2*size-2][0].result<<endl;
	return 0;
}
