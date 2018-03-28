#include <iostream>
#include <vector>

#define R 1000
#define C 1000
#define L 1000
#define H 1000

using namespace std;
int r,c,l,h;

class Slice {

public:
    int rowbeg, rowend;
    int colbeg, colend;
    
    int area () { return (rowend - rowbeg + 1) * (colend - colbeg + 1); }

    void read() { cin>>rowbeg>>colbeg>>rowend>>colend; }
    void write() { cout<<rowbeg<<" "<<colbeg<<" "<<rowend<<" "<<colend<<endl; }
};

class Pizza {

public:

    char cells[R][C];

    bool valid(Slice s) {

        if ( h < s.area() ) return false;

        int tomato = 0;
        int shroom = 0;

        for (int i = s.rowbeg; i <= s.rowend; ++i) {
            
            for (int j = s.colbeg; j <= s.colend; ++j) {
                
                switch(cells[i][j]) {

                    case 'T': ++tomato; break;
                    case 'M': ++shroom; break;
                } 
            }        
        }
       
        if(tomato < l) return false;
        if(shroom < l) return false; 

        return true;
    }

    void read() { for(int i=0; i<r; ++i) { for(int j=0; j<c; ++j) { cin>>cells[i][j]; } } }
    void write() { for(int i=0; i<r; ++i) { for(int j=0; j<c; ++j) { cout<<cells[i][j]; } cout<<endl; } }
};

class Analysis {

public:
    bool valid;
    int covered;
    int overlaps;

    void write() {
        cout<<"Valid: "<<valid<<endl;
        cout<<"Covered: "<<covered<<"/"<<r*c<<endl;
        cout<<"Overlaps: "<<overlaps<<"/"<<r*c<<endl;
    }

    int fitness() {
        return valid ? covered : -overlaps;
    }
};

class Solution {

public:

    Pizza& p;
    vector<Slice> slices;

    Solution(Pizza& p) : p(p) {}

    Analysis analyze() {

        Analysis a;
        a.valid = true;
        a.covered = 0;
        a.overlaps = 0;

        int cellcounts[r][c]; for(int i=0; i<r; ++i) for(int j=0; j<c; ++j) cellcounts[i][j] = 0;

        for(int k=0; k<slices.size(); ++k) {

            if(!p.valid(slices[k])) a.valid = false;
     
            for (int i = slices[k].rowbeg; i <= slices[k].rowend; ++i) {
                for (int j = slices[k].colbeg; j <= slices[k].colend; ++j) {

                   ++cellcounts[i][j];
            
                }        
            }
        }

        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if ( 0 < cellcounts[i][j] ) ++a.covered;
                if ( 1 < cellcounts[i][j] ) ++a.overlaps;
            }
        }
        
        return a;
    }

    void read() { int n; cin>>n; for(int i=0; i<n; ++i) { Slice s; s.read(); slices.push_back(s); } }
    void write() { cout<<slices.size()<<endl; for(int i=0; i<slices.size(); ++i) { slices[i].write(); } }
};

class Evolution {

    Pizza& p;
    
    vector<Solution> population;


    Evolution(Pizza& p) : p(p) {}

    void begin(int size) {
        
        for(int i=0; i<size; ++i) {
            population.push_back(generate());
        }
    }

    

    Solution generate() {
        Solution s(p);
        return s;
    }

    void mutate (Slice& s) {

    }

    void cross (Slice& sa, Slice& sb) {

    }

};

int main () {

    cin>>r>>c>>l>>h;

    Pizza p;
    p.read();
    p.write();

    Solution s(p);
    s.read();
    s.write();

    s.analyze().write();
    cout<<s.analyze().fitness()<<endl;
    
    return 0;
}
