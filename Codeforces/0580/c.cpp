#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {


    int n, m;
    cin>>n>>m;

    vector<int> cats;
    cats.resize(n);

    vector<vector<int> > edges;
    edges.resize(n);

    for(int i=0; i<n; ++i) {

        cin>>cats[i];
    } 

    int x,y;
    for(int i=0; i<n-1; ++i) {
        cin>>x>>y;
        --x;
        --y; 
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    stack<int> frontier;

    vector<bool> visited;
    visited.resize(n);
    for(int i=0; i<n; ++i) visited[i] = false;
 
    vector<bool> found;
    found.resize(n);
    for(int i=0; i<n; ++i) found[i] = false;
    
    frontier.push(0);
    found[0] = true;
  
    vector<int> weight;
    weight.resize(n);
    for(int i=0; i<n; ++i) weight[i] = -1;
    weight[0] = cats[0];
 
    vector<int> maxweight;
    maxweight.resize(n);
    for(int i=0; i<n; ++i) maxweight[i] = -1;
    maxweight[0] = cats[0];
 

    while(!frontier.empty()) {

        int curr = frontier.top();
        frontier.pop();
        visited[curr] = true;

        for(int i=0; i<edges[curr].size(); ++i) {

            int e = edges[curr][i];
            if(!found[e]) {
                frontier.push(e); 
                found[e] = true;
            }

            if(cats[e] == 0) weight[e] = 0;
            else if(weight[e] == -1 ||  weight[e] < weight[curr] + cats[e]) {
                
                    weight[e] = weight[curr] + cats[e]; 
            }

            if(maxweight[e] < maxweight[curr]) maxweight[e] = maxweight[curr];
            if(maxweight[e] < weight[e]) maxweight[e] = weight[e];
        }
    }

    int count = 0;
    for(int i=1; i<n; ++i) {
        if(edges[i].size() > 1) continue;
        if(maxweight[i] == -1) continue;
        if(maxweight[i] <= m) count++;
    }

    cout<<count<<endl;

    return 0;
}
