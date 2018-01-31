#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;

	for(int c=1; c<=t; ++c) {
		
		int n,m;
		cin>>n>>m;
		
		int pc=0, xc=0;
		int rowOfO=0, colOfO = 0;
		int pj[n], xi[n],xj[n];

		for(int i=0; i<n; ++i) {
			pj[i] = 0;
			xi[i] = 0;
			xj[i] = 0;
		}

		char tmp;
		
		for(int i=0; i<m; ++i) {
			
			cin>>tmp;

			int rowTmp;

			switch(tmp) {

				case 'o': 
				   if(colOfO != 0)
					cout<<"We had an o before."<<endl;
				   else {
					cin>>rowTmp;
					if(rowOfO != 0 && rowTmp!=rowOfO) {
						cout<<"+es can be in rows where o is not present."<<endl;
					}
					rowOfO = rowTmp;
					cin>>colOfO;
				   }
				break;


				case '+':
					cin>>rowTmp;
					if(rowOfO != 0 && rowTmp!=rowOfO) {
						cout<<"+es can be in rows where o is not present."<<endl;
					}
					rowOfO = rowTmp;

					cin>>pj[pc++];

				case 'x':
					cin>>xi[xc]>>xj[xc];
					
					++xc;
						
			}

		}
		

	}

	return 0;
}
