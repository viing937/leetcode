#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt == -1)
                return false;
            if (preorder[i] >= '0' && preorder[i] <= '9')
                cnt += 1;
            if (preorder[i] == '#')
                cnt -= 1;
            while (i < preorder.size() && preorder[i] != ',')
                i += 1;
        }
        return cnt == -1;
    }
};

int main() {
    return 0;
}
