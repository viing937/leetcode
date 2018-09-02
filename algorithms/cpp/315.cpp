#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    struct Node {
        int key;
        int less, dup;
        Node *left, *right;
        Node(int x) : key(x), less(0), dup(1), left(NULL), right(NULL) {}
        ~Node() {
            if (left) delete left;
            if (right) delete right;
        }
    };
    Node *insertNode(Node *node, int num, int i, vector<int> &result, int preCnt) {
        if (!node) {
            node = new Node(num);
            result[i] = preCnt;
        }
        else if (num < node->key) {
            node->less += 1;
            node->left = insertNode(node->left, num, i, result, preCnt);
        } else if (num == node->key) {
            node->dup += 1;
            result[i] = preCnt + node->less;
        } else {
            node->right = insertNode(node->right, num, i, result, preCnt + node->less + node->dup);
        }
        return node;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        Node *node = NULL;
        for (int i = nums.size()-1; i >= 0; i--) {
            node = insertNode(node, nums[i], i, result, 0);
        }
        if (node) delete node;
        return result;
    }
};

int main() {
    return 0;
}
