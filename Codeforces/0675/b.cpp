#include <iostream>

using namespace std;

int main () {
	long long n,a,b,c,d;
	
	cin>>n>>a>>b>>c>>d;
	int sum;	
	int sum1 = a+b;
	int sum2 = a+c;
	int sum3 = c+d;
	int sum4 = b+d;
	int cnt = 0;
	for(int i=1; i<=n; ++i) {
		sum = sum1+i;
		if(1<=(sum-sum2) && (sum-sum2)<=n) if(1<=(sum-sum3) && (sum-sum3)<=n) if(1<=(sum-sum4) && (sum-sum4)<=n) ++cnt;
		
	}
	cout<<cnt*n<<endl;
	return 0;
}
