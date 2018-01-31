#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> nums;
    int tmp;
    int cnt = 0;
    for(int i=0; i<n; ++i)
    {
        cin>>tmp;
        for(int twoexp = 1; 0<twoexp; twoexp = twoexp<<1)
            if(tmp<twoexp && nums.find(twoexp-tmp) != nums.end())
            {
                cnt+=nums[twoexp-tmp];
                cout<<tmp<<" + "<<twoexp-tmp<<" = "<<twoexp<<" Times "<<nums[twoexp-tmp]<<endl;
            }

        ++nums[tmp];
    }
    cout<<cnt<<endl;
    return 0;
}
