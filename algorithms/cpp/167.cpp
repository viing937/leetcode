#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int binary(int left, int right, vector<int> &numbers, int target) {
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (numbers[mid] == target)
                return mid;
            else if (numbers[mid] < target)
                return binary(mid+1, right, numbers, target);
            else
                return binary(left, mid-1, numbers, target);
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();

        vector<int> result;
        for (int i = 0; i < n; i++) {
            int idx1 = i, idx2 = binary(i+1, n-1, numbers, target-numbers[i]);
            if (idx2 >= 0) {
                result.push_back(idx1+1);
                result.push_back(idx2+1);
                break;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
