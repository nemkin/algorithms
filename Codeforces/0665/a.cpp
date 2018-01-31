#include <iostream>
using namespace std;
int main() {
	int aperiod, aduration;
	int bperiod, bduration;
	string start;
	int startint;

	cin>>aperiod>>aduration>>bperiod>>bduration;
	cin>>start;
	
	startint = (int)(start[0]-'0')*10+(int)(start[1]-'0');
	startint *= 60;
	startint += (int)(start[3]-'0')*10+(int)(start[4]-'0');
	
	int firsttomeet = startint+1-bduration;
	int startoffirst = 5*60;
	while(startoffirst<firsttomeet) startoffirst+=bperiod;

	int lasttomeet = startint+aduration-1;
	int startoflast = 5*60;
	while(startoflast<lasttomeet) startoflast+=bperiod;
	if(lasttomeet!=startoflast) startoflast-=bperiod;
	while((23*60+59)<startoflast) startoflast-=bperiod;
	
	if(startoffirst<=startoflast) cout<<(startoflast-startoffirst)/bperiod+1<<endl;
	else cout<<0<<endl;

	return 0;
}
