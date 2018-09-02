#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    struct Pair {
        int idx;
        pair<int, int> p;
        long long sum;

        Pair(int idx, int x, int y) {
            this->idx = idx;
            this->p = make_pair(x, y);
            this->sum = (long long)x + (long long)y;
        }

        bool operator <(const Pair &t) const{
            return (sum < t.sum);
        }
    };
public:
    vector< pair<int, int> > kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector< pair<int, int> > result;

        if (nums1.size() == 0 || nums2.size() == 0)
            return result;

        multiset<Pair> heap;

        for (int i = 0; i < nums1.size() && i < k; i++)
            heap.insert(Pair(0, nums1[i], nums2[0]));

        while (!heap.empty() && result.size() < k) {
            Pair t = *heap.begin();
            heap.erase(heap.begin());

            result.push_back(t.p);
            if (t.idx+1 < nums2.size())
                heap.insert(Pair(t.idx+1, t.p.first, nums2[t.idx+1]));
        }

        return result;
    }
};

int main() {
    return 0;
}
