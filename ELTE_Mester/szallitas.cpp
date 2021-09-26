#include <bits/stdc++.h>


#define foreach for(auto &t: T)
using namespace std;

int max(const std::vector<int>& T) {
	int m = INT_MIN;
	foreach {
		if (m < t) m = t;
	}
	return m;
}

int sum(const std::vector<int>& T) {
	int s = 0;
	foreach {
		s += t;
	}
	return s;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& T) {
	int i = 0;
	foreach {
		os << t << " \n"[i==T.size()-1];
		i++;
	}
	return os;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> T(n);
	
	foreach cin >> t;
	
	long long a = max(T)-1;
	long long b = sum(T)+1;
	vector<int> Sb;
	vector<int> S;
	while (a < b-1) {
		long long c = (a+b)/2; // kapacitast tesztelunk
		
		S.clear();
		int n_kamion = 0;
		int kamion_kap = 0;
		S.push_back(1);
		{int i = 1;
		foreach {
			kamion_kap += t;
			if (kamion_kap > c) {
				S.push_back(i);
				kamion_kap = t;
				n_kamion++;
			}
			i++;
		}}
		if (kamion_kap > 0) n_kamion++;
		if (n_kamion <= k) {
			b = c; // jo
			Sb = S; //move(S)
		} else {
			a = c; // rossz
		}
	}
	cout << b << endl;
	cout << Sb;
}
