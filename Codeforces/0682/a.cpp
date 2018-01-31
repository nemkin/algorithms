#include <iostream>
using namespace std;
int main () {
	long long n, m;
	cin>>n>>m;
	
	long long nmod0, nmod1, nmod2, nmod3, nmod4;
	long long mmod0, mmod1, mmod2, mmod3, mmod4;
	
	nmod0 = n/5; 
	nmod1 = n/5; if(0<(n%5)) nmod1++;
	nmod2 = n/5; if(1<(n%5)) nmod2++;
	nmod3 = n/5; if(2<(n%5)) nmod3++;
	nmod4 = n/5; if(3<(n%5)) nmod4++;
	mmod0 = m/5; 
	mmod1 = m/5; if(0<(m%5)) mmod1++;
	mmod2 = m/5; if(1<(m%5)) mmod2++;
	mmod3 = m/5; if(2<(m%5)) mmod3++;
	mmod4 = m/5; if(3<(m%5)) mmod4++;

	long long a = 0;
	a+= nmod1*mmod4;
	a+= nmod2*mmod3;
	a+= nmod3*mmod2;
	a+= nmod4*mmod1;
	a+= nmod0*mmod0;

	cout<<a<<endl;

	return 0;
}
	
