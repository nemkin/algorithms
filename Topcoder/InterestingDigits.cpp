#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

class InterestingDigits {
	public:

		int* retp;

		InterestingDigits():retp(NULL){}

		int sum_of_digits (int base, int num) {
			int sum=0;
			while(1<=num) {
				sum+=num%base;
				num = num/base;
			}
			return sum;
		}

		bool rule_holds (int base, int digit, int mul) {
			if(((sum_of_digits(base,digit*mul))%digit) == 0) return true;
			return false;
		}

		bool interesting(int base, int digit) {
			for(int mul=0; mul*digit<=999; ++mul) {
				if(!rule_holds(base,digit,mul)) return false;
			}
			return true;
		}

		vector<int> digits(int base) {

			std::vector<int> ret;

			for(int i = 2; i<base; ++i) {
				if(interesting(base,i)) ret.push_back(i);
			}

			return ret;
		}

		~InterestingDigits() {
			if(retp!=NULL) free(retp);
		}
};

int main () {
	InterestingDigits().digits(10);
	return 0;
}
