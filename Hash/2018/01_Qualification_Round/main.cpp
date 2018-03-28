#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int R,C,F,N,B,T;

typedef struct {

    int n;
    int sx, sy;
    int ex, ey;
    int st, et;

    bool done;

} RIDE;

RIDE rides[3000][2000];

int length(RIDE a) {

    return abs(a.sx-a.ex) + abs(a.sy-a.ey);
}

int dist(RIDE a, RIDE b) {

    return abs(b.sx-a.ex) + abs(b.sy-a.ey);
}

pair<int,int> find(int x, int y) {

    set<pair<int,int>> closed;
    set<pair<int,int>> openset;
    queue<pair<int,int>> open;
    
    open.push(make_pair(x,y));

    while(!open.empty()) {

        pair<int,int> curr = open.front();
        closed.insert(curr);
        open.pop();

        if(rides[curr.first][curr.second].sx != -1) return curr;

        pair<int,int> a;

        a = make_pair(curr.first-1, curr.second);
        if(0<=a.first && closed.find(a) == closed.end() && openset.find(a) == openset.end()) {
            open.push(a);
            openset.insert(a);
        }

        a = make_pair(curr.first+1, curr.second);
        if(a.first<R && closed.find(a) == closed.end() && openset.find(a) == openset.end()) {
            open.push(a);
            openset.insert(a);
        }

        a = make_pair(curr.first, curr.second-1);
        if(0<=a.second && closed.find(a) == closed.end() && openset.find(a) == openset.end()) {
            open.push(a);
            openset.insert(a);
        }

        a = make_pair(curr.first, curr.second+1);
        if(a.second<C && closed.find(a) == closed.end() && openset.find(a) == openset.end()) {
            open.push(a);
            openset.insert(a);
        }

    }
    
    return make_pair(-1,-1);
}

int main() {

    cin>>R>>C>>F>>N>>B>>T;

    for(int i=0; i<R; ++i) for(int j=0; j<C; ++j) {

        rides[i][j].sx = -1;
    }

    for(int i=0; i<N; ++i) {
        
        RIDE r;
        r.n = i; 
        r.done = false;
        
        cin>>r.sx
           >>r.sy
           >>r.ex
           >>r.ey
           >>r.st
           >>r.et;

        rides[r.sx][r.sy] = r;
    }

    vector<vector<int>> sol;

    sol.resize(F);

    int cx;
    int cy;

    for(int i=0; i<F; ++i) {
       
        cx = 0;
        cy = 0; 
        pair<int,int> a = find(cx,cy);
       
        cerr<<i<<"/"<<F<<endl;
        int t = 0;
        RIDE prev;
        prev.sx = -1; 

        while(a.first != -1) {

            if(prev.sx != -1) t+= dist(prev, rides[a.first][a.second]);
            t+= length(rides[a.first][a.second]);
            if(T<t) break;

            sol[i].push_back(rides[a.first][a.second].n);
            prev = rides[a.first][a.second];

            rides[a.first][a.second].sx = -1;

            cx = rides[a.first][a.second].ex;
            cy = rides[a.first][a.second].ey;

            a = find(cx,cy);
        }
 
        cout<<sol[i].size();

        if(sol[i].size() != 0) cout<<' ';

        for(int j=0; j<sol[i].size(); ++j) {
            cout<<sol[i][j];

            if(j!=(sol[i].size()-1)) cout<<' ';
        }
        
        cout<<endl;        
    }

    return 0;
}
