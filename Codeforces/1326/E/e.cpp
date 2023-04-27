#include <bits/stdc++.h>

using namespace std;

class Interval {
public:
  int left;
  int right;

  Interval() {}
  Interval(int left, int right) : left(left), right(right) { }

  int mid() { return (left + right) / 2; }

  Interval left_half() { return Interval(left, mid()); }
  Interval right_half() { return Interval(mid() + 1, right); }

  Interval left_part(Interval other) { return Interval(left, min(other.right, mid())); }
  Interval right_part(Interval other) { return Interval(max(other.left, mid()+1), right); }

  bool is_single() { return left == right; }
  bool is_invalid() {return left > right; }
};

class SegmentTreeNode {
public:

  int index;
  Interval interval;

  bool is_leaf() { return interval.is_single(); }

  static SegmentTreeNode root(int size) {
    auto node = SegmentTreeNode();
    node.index = 1;
    node.interval = Interval(0, size);
    return node;
  }

  SegmentTreeNode left_node() {
    auto node = SegmentTreeNode();
    node.index = index * 2;
    node.interval = interval.left_half();
    return node;
  }

  SegmentTreeNode right_node() {
    auto node = SegmentTreeNode();
    node.index = index * 2 + 1;
    node.interval = interval.right_half();
    return node;
  }


  SegmentTreeNode follow(int position) {
    if (position <= interval.mid()) {
      return left_node();
    } else {
      return right_node();
    }
  }
};

class SegmentTree {

private:
  vector<int> _data;
  vector<int> _max_prefix_sum;

  SegmentTreeNode root() { return SegmentTreeNode::root(_data.size()); }

  void restore(SegmentTreeNode node) {
    _data[node.index] = max(
      _data[node.left_node().index],
      _data[node.right_node().index]);
  }

  void build(vector<int>& from, SegmentTreeNode node) {
    cout << "node-index:" << node.index << endl;
    cout << "node-left:" << node.interval.left << endl;
    cout << "node-right:" << node.interval.right << endl;
    if (node.is_leaf()) {
        _data[node.index] = from[node.interval.left]; 
        return;
    }

    build(from, node.left_node());
    build(from, node.right_node());

    restore(node);
  }

  int max(SegmentTreeNode node, Interval query) {
    if (query.is_invalid()) return 0;

    if (node.is_leaf()) return _data[node.index];

    return std::max(
      max(node.left_node(), node.interval.left_part(query)),
      max(node.right_node(), node.interval.right_part(query)));
  }

  void set(SegmentTreeNode node, int position, int new_val) {
    if (node.is_leaf()) {
        _data[node.index] = new_val;
        return;
    } 

    set(node.follow(position), position, new_val);

    restore(node);
  }

  void increment_interval(SegmentTreeNode node, Interval where, int increment) {
    if (left > right) return;

    if (node.is_leaf()) {
        _data[node.index] += increment;
        return;
    } 

    increment_interval(node.left_node(), node.interval.left_part(where), increment);
    increment_interval(node.right_node(), node.interval.right_part(where), increment);

    restore(node);
  }

public:
  SegmentTree(vector<int>&& a) : 
    _data(4 * a.size()),
    _max_prefix_sum(4*a.size()) { 
    cout << "size:" << a.size() << endl;
    build(a, root());
  }

  int max(int left, int right) { return max(root(), Interval(left, right)); }

  int get(int position) { return max(position, position); }
  void set(int position, int new_val) { set(root(), position, new_val); }

  void add(int position, int diff) {
    auto curr = get(position);
    set(position, curr+diff);
  }

  void add(int left, int right, int diff) {
    increment_interval(root(), Interval(left, right), diff);
  }
};

int n;
vector<int> p;
vector<int> q;

vector<int> p_inv;

int main() {
  cin >> n;
  p.resize(n);
  p_inv.resize(n);
  q.resize(n);

  for(int i=0; i<n; ++i) { cin>>p[i]; --p[i]; }
  for(int i=0; i<n; ++i) { cin>>q[i]; --q[i]; }

  for(int i=0; i<n; ++i) p_inv[p[i]] = i;

  int x = n;

  SegmentTree t(vector<int>(n, 0));

  int current_solution = n-1;
  for(int i = 0; i<n; ++i) {
    cout << current_solution << " ";
    //t.add(0, q[i], -1);
    //while(t.get(0) <= 0) {
      //t.add(0, p_inv[--current_solution], 1);
    //}
  }

  return 0;
}