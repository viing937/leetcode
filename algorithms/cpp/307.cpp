#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> segTree;
    int segStart, segEnd;
    void build(int root, const vector<int> &nums, int start, int end) {
        if (start == end)
            segTree[root] = nums[start];
        else {
            int mid = (start+end)/2;
            build(root*2+1, nums, start, mid);
            build(root*2+2, nums, mid+1, end);
            segTree[root] = segTree[root*2+1] + segTree[root*2+2];
        }
    }
    int query(int root, int nstart, int nend, int qstart, int qend) {
        if (qstart > nend || qend < nstart)
            return 0;
        if (qstart <= nstart && qend >= nend)
            return segTree[root];
        int mid = (nstart+nend)/2;
        return query(root*2+1, nstart, mid, qstart, qend)
             + query(root*2+2, mid+1, nend, qstart, qend);
    }
    void updateOne(int root, int start, int end, int idx, int val) {
        if (start == end) {
            if (start == idx)
                segTree[root] = val;
            return;
        }
        int mid = (start+end)/2;
        if (idx <= mid)
            updateOne(root*2+1, start, mid, idx, val);
        else
            updateOne(root*2+2, mid+1, end, idx, val);
        segTree[root] = segTree[root*2+1] + segTree[root*2+2];
    }
public:
    NumArray(vector<int> nums) {
        if (nums.size() == 0)
            return;
        segTree = vector<int>(nums.size()<<2, 0);
        segStart = 0, segEnd = nums.size()-1;
        build(0, nums, segStart, segEnd);
    }
    void update(int i, int val) {
        updateOne(0, segStart, segEnd, i, val);
    }
    int sumRange(int i, int j) {
        return query(0, segStart, segEnd, i, j);
    }
};

int main() {
    return 0;
}
