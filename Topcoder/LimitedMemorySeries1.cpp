#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LimitedMemorySeries1 {
	public:

		//Input. 
		int n;
		int x0;
		long long a;
		long long b;
		vector<int> query;

		// Place data. For every query we set the partitionIndex to which partition
		// contains the element with that index and placeInsidePartition to 
		// where that element is in the partition. Both indexes start with 0.
		int partitionIndex;
		int placeInsidePartition;

		// Holds the number of elements in all the partitions.
		int numOfElements[44722];

		// Initialize the input data. To be called first. 
		void init(int& n, int& x0, long long& a, long long& b, vector<int>& query) {
			this->n = n;
			this->x0 = x0;
			this->a = a;
			this->b = b;
			this->query = query;
		}

		// Returns the next element in the series.
		int next(int element) {
			return (element*a+b)%1000000007;
		}

		// Returns the index of the partition where the element is.
		int whichPartition(int element) {
			return (element+1000000006)/44721;
		}

		int globalNumberToLocalNumber(int element) {
			return (element+1000000006)%44721;
		}

		int localNumberToGlobalNumber(int localelement, int partitionindex) {
			return (partitionindex*44721+localelement)-1000000006;
		}

		// First element in the partition with the index given.
		int firstElement(int partitionIndex) {
			return partitionIndex*44721-1000000006;
		}

		// Last element in the partition with the index given.
		int lastElement(int partitionIndex) {
			return partitionIndex*44721-1000000006+44720;
		}

		// Fills numOfElements with the correct data based on the input.	
		void  initNumOfElements() {

			for(int i=0; i<44722; ++i) {
				numOfElements[i] = 0;
			}

			int element = x0;
			++numOfElements[whichPartition(element)];

			for(int i=1; i<n; ++i) {
				element = next(element);
				++numOfElements[whichPartition(element)];
			}
		}

		// Gets the queried position and sets the variables containing 
		// the partition's index and the place inside that partition.
		void setPlaceData (int query) {

			int indexFirst;
			int indexLast = -1;

			for(int i=0; i<44722; ++i) {
				if(numOfElements[i] != 0) {
					indexFirst = indexLast+1;
					indexLast += numOfElements[i];
					if(indexFirst<=query && query<=indexLast) {
						partitionIndex = i;
						placeInsidePartition = query-indexFirst;
						return;    
					}
				}        
			}
		} 

		// Returns the element of the series at the queried place. 
		// Called only after setPlaceData(int).
		int getNumberAtPlaceData () {
			int sorter[44721];

			for (int i=0; i<44721; ++i) {
				sorter[i] = 0;
			}

			int element = x0;
			if(whichPartition(element) == partitionIndex) {
				++sorter[globalNumberToLocalNumber(element)];
			}

			for(int i=1; i<n; ++i) {
				element = next(element);
				if(whichPartition(element) == partitionIndex) {
					++sorter[globalNumberToLocalNumber(element)];
				}	    
			}

			int curr = 0;
           
            curr = sorter[0];
            
			for(int i=1; i<44721; ++i) {
				if(placeInsidePartition<curr) return localNumberToGlobalNumber(i-1, partitionIndex);
				curr+=sorter[i];
			}
			if(placeInsidePartition<curr) return localNumberToGlobalNumber(44721-1, partitionIndex);

			return -1;	 
		}

		long long getSum(int n, int x0, long long a, long long b, vector <int> query) {

			init(n,x0,a,b,query);

			initNumOfElements();
			
			int num;
			long long sum = 0;

			for(int i=0; i<query.size(); ++i) {
				setPlaceData(query[i]);
				num = getNumberAtPlaceData();	
				sum+=num;
			}

			return sum;
		}

};

int main () {

	int n, x0;
	long long a, b;
	vector<int> query;

	int num;
	char sep;

	cin>>n>>x0>>a>>b;
	cin>>sep;

	while(sep!='}') {
		cin>>num;
		query.push_back(num);
		cin>>sep;
	}

	LimitedMemorySeries1 lms1;
	cout<<lms1.getSum(n, x0, a, b, query)<<endl;

	return 0;
}
