#include <iostream>
#include <set>

using namespace std;

typedef struct {

    int index;
    int low_link;
    bool on_stack;

    vertex() {
        
        index = -1;
        on_stack = false;
    }

} vertex;

// Takes the number of nodes (they are numbered 0 - n-1).
// Takes the edges.
// Returns set of strongly connected nodes.
set<vector<int> > tarjan(vector<vertex> V, vector<pair<int, int>> E) {

  int index = 0;

  vector<int> S;   

  for (auto v : V) {
    if (v.index == -1) {
      strong_connect(V.size(), v, S)
    }
  }

}

void strong_connect(int n, vertex& v, vector<int>& S)
    // Set the depth index for v to the smallest unused index
    v.index = n;
    v.lowlink = n;
    v.on_stack := true

    index := index + 1
    S.push(v)

    // Consider successors of v
    for each (v, w) in E do
      if (w.index is undefined) then
        // Successor w has not yet been visited; recurse on it
        strongconnect(w)
        v.lowlink  := min(v.lowlink, w.lowlink)
      else if (w.onStack) then
        // Successor w is in stack S and hence in the current SCC
        // Note: The next line may look odd - but is correct.
        // It says w.index not w.lowlink; that is deliberate and from the original paper
        v.lowlink  := min(v.lowlink, w.index)
      end if
    end for

    // If v is a root node, pop the stack and generate an SCC
    if (v.lowlink = v.index) then
      start a new strongly connected component
      repeat
        w := S.pop()
        w.onStack := false
        add w to current strongly connected component
      while (w != v)
      output the current strongly connected component
    end if
  end function
