#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <iomanip>

using namespace std;

int main() {

    int n;
    cin>>n;

    vector<set<int>> edges;
    edges.resize(n);

    int depth[n] = {0};
    bool found[n] = {false};

    int x,y;

    for(int i=0; i<(n-1); ++i) {
        cin>>x>>y; --x; --y;

        edges[x].insert(y);
        edges[y].insert(x);
    }

    queue<int> frontier;

    frontier.push(0);

    depth[0] = 1;
    found[0] = true;

    int curr;
    while(!frontier.empty()) {
        curr = frontier.front();
        frontier.pop();

        for(int child: edges[curr]) {
            if(!found[child]) {
                depth[child] = depth[curr]+1;
                frontier.push(child);
                found[child] = true;
            }
        }
    }
   
    double result = 0.0;

    for(int i=0; i<n; ++i) {

        result += 1/(double)(depth[i]);
    }
    
    cout<<fixed<<setprecision(numeric_limits<double>::max_digits10);
    cout<<result<<endl;
 
    return 0;
}
