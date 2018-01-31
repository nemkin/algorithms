#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <set>
using namespace std;

int n, m;
int t;

vector<string> varosok;
map<string, int> varosok_decode;
  
vector<int> biciklis_tavok;

//Végváros - Kezdővárosok, Táv
map<int, vector<pair<int,int>>> kompos_tavok_dp;
map<pair<int,int>, int> kompos_tavok;

//i. varoshoz : ossztav = suly, biciklistav = ertek (maximalizal)
vector<map<int,int>> dp;
vector<map<int,int>> dp_from;
//Index: eddig a városig jutottunk el a kezdővárostól
//Ennyi időt használtam el
//dp[i] = i-1 -ből jöttem biciklivel vagy valamelyik kompútvonalon

// kompútvonal indexelése idővel és végvárossal


int main() {

//Read inputs

	cin>>n;

	varosok.resize(n);
	biciklis_tavok.resize(n);
	dp.resize(n+1);
	dp_from.resize(n+1);

	for(int i=0; i<n; ++i) {
		cin>>varosok[i];
		varosok_decode[varosok[i]] = i;
	}
	

	for(int i=0; i<n; ++i) cin>>biciklis_tavok[i];

	cin>>m;

	string from_varos,to_varos;
	int tav;

	for(int i=0; i<m; ++i) {
		cin>>from_varos>>to_varos>>tav;
		kompos_tavok_dp[varosok_decode[to_varos]].push_back(make_pair(varosok_decode[from_varos],tav));
		kompos_tavok[make_pair(varosok_decode[from_varos],varosok_decode[to_varos])] = tav;
	}

	cin>>t;


	//Az elso varosba 0 ido alatt el lehet jutni, 0 bicikliertekkel.
	dp[0].insert(make_pair(0,0));

	for(int i=1; i<n+1; ++i) {

		//Biciklivel jovunk i-be i-1-bol:
		for(auto pair : dp[i-1]) {

			auto proposed = make_pair(
				pair.first+biciklis_tavok[i-1],
				pair.second+biciklis_tavok[i-1]);
	
			if(dp[i].find(proposed.first) == dp[i].end() ||
			   proposed.second > dp[i][proposed.first]) {
			
				dp[i][proposed.first] = proposed.second;
				dp_from[i][proposed.first] = i-1;
			   }	
		}

//Végváros - Kezdővárosok, Táv
//map<int, vector<pair<int,int>>> kompos_tavok_dp;

//i. varoshoz : ossztav = suly, biciklistav = ertek (maximalizal)
//vector<map<int,int>> dp;


		//Komppal jovunk i-be:
		for(auto pair : kompos_tavok_dp[i%n]) {
			for(auto dppair : dp[pair.first]) {
				
				auto proposed = make_pair(
					dppair.first + pair.second,
					dppair.second
				);

				if(dp[i].find(proposed.first) == dp[i].end() ||
			   		proposed.second > dp[i][proposed.first])  {

					dp[i][proposed.first] = proposed.second;
					dp_from[i][proposed.first] = pair.first;
				}	
				
			}	
		}	
		
	}

	//for(int i=0; i<n+1; ++i)
	int i=n;
	
	auto after = dp[i].upper_bound(t);
	
	if(after == dp[i].begin()) {
		cout<<"WUT"<<endl;
	} else {
	
		vector<pair<string,string>> kompok;
	
		after = --after;
		auto pair = *(after);
			int varos = n;
			int tav = pair.first;
			while(varos!=0) {
				int ujvaros = dp_from[varos][tav];
				if(ujvaros == varos-1)
					tav -= biciklis_tavok[ujvaros];
				else {
					tav -= kompos_tavok[make_pair(ujvaros,varos%n)];
					kompok.push_back(make_pair(varosok[ujvaros],varosok[varos%n]));
				}
				varos = ujvaros; 
			}
		cout<<kompok.size()<<endl;
		for(int i=0; i<kompok.size(); ++i) {
			cout<<kompok[i].first<<' '<<kompok[i].second<<endl;
		}
	}	
	
	return 0;
}

