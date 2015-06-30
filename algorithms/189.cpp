#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void swapInt(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void swapArr(vector<int> &arr, int l, int r)
    {
        for ( int i = 0; l+i < r-i; i++ )
            swapInt(arr[l+i], arr[r-i]);
    }
public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        k = k%n;
        swapArr(nums, 0, n-1-k);
        swapArr(nums, n-k, n-1);
        swapArr(nums, 0, n-1);
    }
};

int main()
{
    //int arr[] = {1,2,3,4,5,6,7};
    int arr[] = {1,2};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution solution;
    solution.rotate(nums, 0);
    for ( auto it = nums.begin(); it != nums.end(); it++ )
        cout << *it << endl;
    return 0;
}
