#include <iostream>
using namespace std;

int main () {
	int t;
	cin>>t;

	for (int cas = 1; cas <= t; ++ cas) {
		cout<<"Case #"<<cas<<":"<<endl;

		int r,c;
		cin>>r>>c;
		
		char cake[r][c];

		for(int i=0; i<r; ++i)
		  for(int j=0; j<c; ++j)
			cin>>cake[i][j];

		for(int i=0; i<r; ++i) {
	           bool b=false;
		   int lettercol = 0;
	           while(lettercol<c && cake[i][lettercol] == '?') {
			++lettercol;
			if(lettercol>=c) {
			    b=true;
			}
	           }
		  
		   if(!b) { 
		   	char letter = cake[i][lettercol];
		   	for(int j=0; j<c; ++j) {
				if(cake[i][j] == '?') cake[i][j] = letter;
				else letter = cake[i][j];
		   	}
		  }
		}
		
		for(int j=0; j<c; ++j) {
			bool b=false;
			int letterrow = 0;
			while(letterrow<r && cake[letterrow][j] == '?') {
				++letterrow;
				if(letterrow>=r) {
					b = true;
				}
	
			}
			if (!b) {
				char letter = cake[letterrow][j];
				for(int i=0; i<r; ++i) {
					if(cake[i][j] == '?') cake[i][j] = letter;
					else letter = cake[i][j];
				}
			}
		}	
		
		for(int i=0; i<r; ++i) {
			for(int j=0; j<c; ++j) {
				cout<<cake[i][j];
			}
			cout<<endl;
		}
	}
	
	return 0;
}
