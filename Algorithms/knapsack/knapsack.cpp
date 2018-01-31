#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main () {

   	//Weight limit.
	int c;
	//Number of objects.
	int n; 
	cin>>c>>n;

	//Object weights.
	int weight[n];
	//Object values.
	int value[n];

	//Dp table for sum of values.
	int dp[c+1][2];
	//Dp table for the objects needed to get the value. 
	set<int> dpobjects[c+1][2]; 

	//Read weights and values.
	for(int i=0; i<n; ++i)
		cin>>weight[i]>>value[i];

	//Init local variables to zero.
	for(int i=0; i<c+1; ++i)
		for(int j=0; j<2; ++j)
			dp[i][j] = 0;

	//Fill dp tables.
	for(int i=0; i<n; ++i) {
		for(int w=1; w<=c; ++w) {

			//We either use the current object.
			if( (0<=w-weight[i]) && (dp[w][(i+1)%2] < dp[w-weight[i]][(i+1)%2] + value[i])) {
				
					dp[w][i%2] = dp[w-weight[i]][(i+1)%2] + value[i];

					dpobjects[w][i%2] = dpobjects[w-weight[i]][(i+1)%2];
					dpobjects[w][i%2].insert(i);

			//Or we don't use it.
			} else {
				dp[w][i%2] = dp[w][(i+1)%2];
				dpobjects[w][i%2] = dpobjects[w][(i+1)%2];
			}
		}
		
		//Clean up the dpobjects from the previous iteration, no longer needed.
		for(int w=1; w<=c; ++w) {
			dpobjects[w][(i+1)%2].clear();
		}
	}

	//Solution.
	cout<<dp[c][(n+1)%2]<<endl;
	for(set<int>::iterator i = dpobjects[c][(n+1)%2].begin(); i!=dpobjects[c][(n+1)%2].end(); i++) {
		cout<<(*i)+1<<' ';
	}
	cout<<endl;
	return 0;
}

