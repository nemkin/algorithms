#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

unordered_map<int, string> name;
set<int> volt;
set<int> bizt;
unordered_map<int, int> cnt;
unordered_map<int, int> sumval;

int main(){

    int n;
    cin>>n;

    string s;

    for (int i=0; i<n; i++) {
        int id;
        //string name;
        cin>>id;

        getline(cin, s);
        name[id] = s;

        bizt.insert(id);
        volt.insert(id);
    }

    string line;
    while (getline(cin, s)) {
        if (s.length() == 0)
            continue;
        if ((signed)s.find(" ") == -1) {
            volt.insert(atoi(s.c_str()));
        }
        else {
            string s1 = s.substr(0, s.find(" "));
            string s2 = s.substr(s.find(" ")+1, s.length()-s.find(" ")-1);
            int a1 = atoi(s1.c_str());
            int a2 = atoi(s2.c_str());

            cnt[a1]++;
            sumval[a1] += a2;
            volt.insert(a1);
        }
    }


    int totalsum = 0;
    for (auto it : sumval) {
        if (bizt.find(it.first) != bizt.end())
            totalsum += it.second;
        //cout << "[" << it.first <<" " << it.second << "]"<< endl;
    }
    cout << "Total value of medical services: " << totalsum << endl<<endl;

    int maxnum = 0;
    for (auto it : cnt) {
        if (bizt.find(it.first) != bizt.end()) {
            if (it.second > maxnum)
                maxnum = it.second;
        }
    }
    map<int, int> xx;
    cout<<"Maximum number of medical services: " <<maxnum<<endl;
    for (auto it : cnt) {
        if (bizt.find(it.first) != bizt.end()) {
            if (it.second == maxnum)
                xx[it.first] = it.second;//cout <<" " << it.first <<name[it.first] <<endl;

        }
    }
    for (auto it : xx) {
        cout <<" " << it.first <<name[it.first] <<endl;
    }

    cout<<endl;

    int maxsum = 0;

    for (auto it : sumval) {
        if (bizt.find(it.first) != bizt.end()) {
            if (it.second > maxsum)
                maxsum = it.second;
        }
    }



    cout<<"Maximum cumulated value: "<<maxsum<<endl;
    map<int, int> xz;
    for (auto it : sumval) {
        if (bizt.find(it.first) != bizt.end()) {
            if (it.second == maxsum)
                xz[it.first] = it.second;//cout <<" " << it.first <<name[it.first] <<endl;
        }
    }
    for (auto it : xx) {
        cout <<" " << it.first <<name[it.first] <<endl;
    }
    cout<<endl;

    cout << "Persons without insurance: " << volt.size() - bizt.size() << endl;

    return 0;
}
