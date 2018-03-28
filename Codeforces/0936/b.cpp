#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int n, m;
int s;

vector<vector<int> > edges;

vector<int> bef_szam;
vector<int> mely_szam;

vector<bool> ptln;
vector<bool> prs;

int mely_szam_last = 1;
int bef_szam_last = 1;

vector<int> parent_list;

bool is_win = false;
bool is_draw = false;

void DFS(int s, bool prs_pari) {

    parent_list.push_back(s);

    if(!prs_pari && edges[s].size() == 0) {

        is_win = true;
        cout<<"Win"<<endl;
        
        for(int i=0; i<parent_list.size(); ++i) {
            
            cout<<parent_list[i]+1<<' '; 
        }
        cout<<endl;
        
        parent_list.pop_back();
        exit(0);
    }

    if(prs_pari && prs[s]) {
        parent_list.pop_back();
        return;
    }
    if(!prs_pari && ptln[s]) {
        parent_list.pop_back();
        return;
    }

    prs[s] = prs[s] || prs_pari;
    ptln[s] = ptln[s] || !prs_pari;

    mely_szam[s] = mely_szam_last++; 
    
    for(int i=0; i<edges[s].size(); ++i) {

        // Visszaél:

        if(mely_szam[edges[s][i]] != 0 && bef_szam[edges[s][i]] == 0) {

            is_draw = true;
        }
 
        DFS(edges[s][i], !prs_pari);
    }

    bef_szam[s] = bef_szam_last++;    

    parent_list.pop_back();
};

int main() {

    try {
    cin>>n>>m;

    edges.resize(n);

    for(int i=0; i<n; ++i) {
        int count; cin>>count;

        for(int j=0; j<count; ++j) {

            int c; cin>>c; --c;
            edges[i].push_back(c);
        }
    }

    cin>>s; --s;

    bef_szam.resize(n);
    mely_szam.resize(n);
    ptln.resize(n);
    prs.resize(n);
    
    DFS(s, true); 

    if(!is_win) {

            if(is_draw) cout<<"Draw"<<endl;
            else cout<<"Lose"<<endl;
    }
    
    } catch (std::exception& e) {
    }
    return 0;
}
