#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return node;
        if (hash.find(node) == hash.end()) {
            hash[node] = new UndirectedGraphNode(node -> label);
            for (auto x : node->neighbors) {
                (hash[node]->neighbors).push_back(cloneGraph(x));
            }
        }
        return hash[node];
    }
};

int main() {
    return 0;
}
