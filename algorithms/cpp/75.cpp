#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        vector<int> cnt(3,0);
        for ( unsigned int i = 0; i < nums.size(); i++ )
            cnt[nums[i]]++;
        nums.clear();
        for ( unsigned int i = 0; i < 3; i++ )
            while ( cnt[i]-- )
                nums.push_back(i);
        return;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    Solution solution;
    solution.sortColors(nums);
    for ( unsigned int i = 0; i < nums.size(); i++ )
        cout << nums[i] << endl;
    return 0;
}
