#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();

        vector<int> num(n, 1);

        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i-1])
                num[i] = num[i-1] + 1;

        for (int i = n-2; i >= 0; i--)
            if (ratings[i] > ratings[i+1])
                num[i] = max(num[i], num[i+1]+1);

        int result = 0;
        for (int i = 0; i < n; i++)
            result += num[i];

        return result;
    }
};

int main() {
    return 0;
}
