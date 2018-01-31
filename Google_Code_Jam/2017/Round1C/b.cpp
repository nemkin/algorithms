#include <iostream>

using namespace std;

int main() {

	int t;
	cin>>t;
		
	for(int c=1; c<=t; ++c) {
		
		cout<<"Case #"<<c<<": ";

		int ac,aj;
		cin>>ac>>aj;

		int tac[ac][2], taj[aj][2];

		for(int i=0; i<ac; ++i) cin>>tac[i][0]>>tac[i][1];
		for(int i=0; i<aj; ++i) cin>>taj[i][0]>>taj[i][1];

		if((ac==0 && aj==1) || (ac==1 && aj==0) || (ac==0 && aj==0) || (ac==1 && aj==1)) {
			cout<<2<<endl;
			continue;
		}

		if(ac==1 && aj==2) {
			if(tac[0][1]-tac[0][0]<=720) cout<<"2"<<endl;
			else cout<<"4"<<endl;
			continue;
		}
		
		if(ac==2 && aj==1) {
			if(taj[0][1]-taj[0][0]<=720) cout<<"2"<<endl;
			else cout<<"4"<<endl;
			continue;
		}
		
		int cmin=5000, cmax=-1, jmin=5000, jmax=-1;
		
		for(int i=0; i<ac; ++i) {
			if(cmin>tac[i][0]) cmin=tac[i][0];
			if(cmax<tac[i][1]) cmax=tac[i][1];
		}
		for(int i=0; i<aj; ++i) {
			if(jmin>taj[i][0]) jmin=taj[i][0];
			if(jmax<taj[i][1]) jmax=taj[i][1];
		}

		int jbetweenbegin = 5000, jbetweenend=-1;
		for(int i=0; i<aj; ++i) {
			if(jbetweenend<taj[i][0]) jbetweenend=taj[i][0];
			if(jbetweenbegin>taj[i][1]) jbetweenbegin=taj[i][1];
		}
		
		int cbetweenbegin = 5000, cbetweenend=-1;
		for(int i=0; i<ac; ++i) {
			if(cbetweenend<tac[i][0]) cbetweenend=tac[i][0];
			if(cbetweenbegin>tac[i][1]) cbetweenbegin=tac[i][1];
		}

		if((cmin<=jmax || jmin<=cmax) && ((ac!= 0 && (cmax-cmin)<=720) || (aj!=0 && (jmax-jmin)<=720) )) {
			cout<<2<<endl;
			continue;
		}
	
		cout<<4<<endl;
	}

	return 0;
}
