#include <bits/stdc++.h>
using namespace std;

struct Index {
  int x = -1;
  int y = -1;
};

struct Node {
   char type = '.';
   Index top, right, bottom, left;

   bool non_empty() { return type != '.'; }
};

int main()
{
   int n, m; cin>>n>>m;
   
   vector<vector<Node>> room(n, vector<Node>(m));

   for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin >> room[i][j].type;
     }
   }

   Index prev, curr;

   for(curr.x=0; curr.x<n; ++curr.x) {
      for(curr.y=0; curr.y<m; ++curr.y) {
         
         if (poziciok[i][j] != -1) {

            if (csucsok[poziciok[i][j]] == '#') {
               previous = -1;
            } else if(previous != -1) {
               szomszlista[previous].rightN() = poziciok[i][j];
               szomszlista[poziciok[i][j]].leftN() = previous;
               previous = poziciok[i][j];
            } else {
               previous = poziciok[i][j];
            }
         }  
      }
      previous = -1;
   }

   for(int j=0; j<m; ++j) {
      for(int i=0; i<n; ++i) {
         if (poziciok[i][j] != -1) {
            if (csucsok[poziciok[i][j]] == '#') {
               previous = -1;
            } else if(previous != -1) {
               szomszlista[previous].bottomN() = poziciok[i][j];
               szomszlista[poziciok[i][j]].topN() = previous;

               previous = poziciok[i][j];
            } else {
               previous = poziciok[i][j];
            }
         }  
      }
      previous = -1;
   }


   for(int i=0; i<csucsok.size(); ++i) {
      if (csucsok[i] == '/') {
         auto a = szomszlista[i];

         if (a.topN() != -1) szomszlista[a.topN()].bottomN() = a.leftN();
         if (a.leftN() != -1) szomszlista[a.leftN()].rightN() = a.topN();

         if (a.rightN() != -1) szomszlista[a.rightN()].leftN() = a.bottomN();
         if (a.bottomN() != -1) szomszlista[a.bottomN()].topN() = a.rightN();

         szomszlista[i].leftN() = -1;
         szomszlista[i].rightN() = -1;
         szomszlista[i].topN() = -1;
         szomszlista[i].bottomN() = -1;
      }
      if (csucsok[i] == '\\') {
         auto a = szomszlista[i];

         if (a.topN() != -1) {
            szomszlista[a.topN()].bottomN() = a.rightN();
         }

         if (a.rightN() != -1) szomszlista[a.rightN()].leftN() = a.topN();

         if (a.leftN() != -1) szomszlista[a.leftN()].rightN() = a.bottomN();
         if (a.bottomN() != -1) szomszlista[a.bottomN()].topN() = a.leftN();

         szomszlista[i].leftN() = -1;
         szomszlista[i].rightN() = -1;
         szomszlista[i].topN() = -1;
         szomszlista[i].bottomN() = -1;
      }
   }

   vector<int> gargoyleok;
   vector<int> gargoyleInverse(csucsok.size(), -1);

   for(int i=0; i<csucsok.size(); ++i) {
      if(csucsok[i] == 'H' || csucsok[i] == 'V') {
         gargoyleok.push_back(i);
         gargoyleInverse[i] = gargoyleok.size()-1;
      }
   }

   vector<GraphNode> gargoyleSzomszLista(gargoyleok.size());
   for(int i=0; i<gargoyleok.size(); ++i) {
      if(szomszlista[gargoyleok[i]].leftN() != -1)
         gargoyleSzomszLista[i].leftN() = gargoyleInverse[szomszlista[gargoyleok[i]].leftN()];

      if(szomszlista[gargoyleok[i]].rightN() != -1)
         gargoyleSzomszLista[i].rightN() = gargoyleInverse[szomszlista[gargoyleok[i]].rightN()];
      
      if(szomszlista[gargoyleok[i]].topN() != -1)
         gargoyleSzomszLista[i].topN() = gargoyleInverse[szomszlista[gargoyleok[i]].topN()];
      
      if(szomszlista[gargoyleok[i]].bottomN() != -1)
         gargoyleSzomszLista[i].bottomN() = gargoyleInverse[szomszlista[gargoyleok[i]].bottomN()];
   }

   return 0;
}