#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;
int main () {
        int n, m;
        cin>>n>>m;
        long long reps[n];
        bool written[n];
        int ords[m][2];
        bool vord[m];

        for(int i=0; i<m; ++i) {
            vord[i] = true;
        }

        for (int i=0; i<n; ++i) {
            cin>>reps[i];
            written[i] = false;
        }

        for(int i=0; i<m; ++i) {
            cin>>ords[i][0]>>ords[i][1];

            if(ords[i][0] == 2) ords[i][0] = -1;
        }

        int biggest = 0;
        for(int i=m-1; 0<=i; --i) {
            if(biggest<ords[i][1]) {
                biggest = ords[i][1];
            } else {
                vord[i] = false;
            }
        }

        int previ = 0;

        while(vord[previ]!=true) ++previ;

        for(int i=previ+1; i<m; ++i) {
            if(vord[i]) {
                if(ords[previ][0] == ords[i][0]) {
                    vord[i] = false;
                }
                previ = i;
            }
        }

        vector<pair<int,int> > orders;

        for(int i=0; i<m; ++i) {
            if(vord[i]) {
                orders.push_back(pair<int,int>(ords[i][0], ords[i][1]));
            }
        }
        if(orders[0].first == 1) {
            sort(reps, reps+orders[0].second, std::less<int>());
        } else {
            sort(reps, reps+orders[0].second, std::greater<int>());
            for(int i=0; i<orders.size(); ++i) {
                orders[i].second = (n-1)-orders[i].second;
            }
        }

        stack<pair<int,int> > outers;
        int first=0, last=n-1;
        outers.push(pair<int,int>(first, last));
        cout<<endl<<endl;
        cout<<first<<' '<<last<<endl;
        for(int i=1; i<orders.size(); ++i) {
            last = first;
            first -= orders[i].first*(orders[i].second-1);
            outers.push(pair<int,int>(first, last));
            cout<<orders[i].first<<" "<<orders[i].second<<"  "<<first<<' '<<last<<endl;
        }
        cout<<endl;
        cout<<endl;


        for(int i = orders.size()-1; 0<=i; --i) {
            if(orders[i].first == 1) {
                for(int j=outers.top().first; j<=outers.top().second; ++j) {
                    if(!written[j]) {
                        cout<<reps[j]<<' ';
                        written[j] = true;
                    }
                }
            } else {
                for(int j=outers.top().first; outers.top().second<=j; --j) {
                    if(!written[j]) {
                        cout<<reps[j]<<' ';
                        written[j] = true;
                    }
                }

            }
            outers.pop();
        }

        if(orders.size() == 1) {
            for(int j=0; j<n; ++j) {
                cout<<reps[j]<<' ';
            }
        }

        return 0;

}
