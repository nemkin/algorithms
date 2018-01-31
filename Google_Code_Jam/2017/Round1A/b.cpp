#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin>>t;
	for(int cas = 1; cas <=t; ++cas) {

		int n,p;	
		cin>>n>>p;

		int r[n];
		for(int i=0; i<n; ++i) cin>>r[i];

		long long packs[n][p];

		for(int i=0; i<n; ++i) {
			for (int j=0; j<p; ++j) {
				cin>>packs[i][j];
			}
		}

		for(int i=0; i<n; ++i) sort(packs[i], packs[i]+p);        

		int indexes[n] = {0};
		int count = 0;

		bool b = false;        
		while(!b) {
			for(int i=0; i<n; ++i) if(indexes[i]>=p) b=true;

			if(!b) {
				bool somethingworked = false;
				for(long long serving = 1; serving<=(packs[0][indexes[0]]/r[0]+10)*10; ++serving) {
					bool works = true;
					for(int i=0; i<n; ++i) {
						if(!(0.90*r[i]*serving <= packs[i][indexes[i]] && packs[i][indexes[i]] <= r[i]*serving*1.10)) {
							works = false;
							break;
						}
					}
					if(works) {
						++count;
						somethingworked = true;
						for(int i=0; i<n; ++i) ++indexes[i];
						break;
					}
				}
				if(!somethingworked) {

					long long minpackamount = packs[0][indexes[0]];
					int minpackindex = 0;

					for(int i=1; i<n; ++i) {

						if(minpackamount > packs[i][indexes[i]]) {
							minpackamount = packs[i][indexes[i]];
							minpackindex = i;
						} 
					}
					++indexes[minpackindex];
				}

			}
		}
        cout<<"Case #"<<cas<<": "<<count<<endl;
	}

	return 0;
}
