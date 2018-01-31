#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    vector<int> results;
    int a,b,c;
    cin>>a>>b>>c;

    results.push_back(a+b+c);

    results.push_back((a+b)*c);
    results.push_back(a*(b+c));

    results.push_back(a*b+c);
    results.push_back(a+b*c);

    results.push_back(a*b*c);

    cout<<*max_element(results.begin(), results.end());

    return 0;
}
