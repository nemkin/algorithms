#include <iostream>
#include <vector>
using namespace std;
int main () {
    long long start, stop, t;
    cin>>start>>stop>>t;

    long long n;

    vector<long long> customers;
    customers.resize(n);

    for(long long i = 0; i<n; ++i) cin>>customers[i];


    long long minwait = -1;
    long long minarrive = -1;

    for(long long i =0; i<n; ++i) {
        
	if(stop<start+t) break;
	
	long long arrive = customers[i]-1;
	
	if(0<=arrive) {

		if(start<=arrive) {
			minarrive = start;
			minwait=0;
			break;
		}

		long long wait = start-arrive;
	
		if(wait<minwait || minwait==-1) {
			minwait = wait;
			minarrive = arrive;
		}

	}

	if(start<customers[i]) {
		start = customers[i]+t;
	} else {
		start = start+t;
	}

	cout<<start<<" "<<minarrive<<endl;
    }

    cout<<endl<<minwait<<endl<<minarrive<<endl;

    return 0;
}
