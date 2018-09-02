#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    bool insertPoint(int x, int y, int pos, map<pair<int, int>, int> &corners) {
        pair<int, int> point = make_pair(x, y);
        if (corners[point] & 1<<pos)
            return false;
        corners[point] |= 1<<pos;
        return true;
    }
public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        map<pair<int, int>, int> corners;
        for (auto rectangle: rectangles) {
            if (!insertPoint(rectangle[0], rectangle[1], 0, corners))
                return false;
            if (!insertPoint(rectangle[2], rectangle[3], 1, corners))
                return false;
            if (!insertPoint(rectangle[0], rectangle[3], 2, corners))
                return false;
            if (!insertPoint(rectangle[2], rectangle[1], 3, corners))
                return false;
        }
        int flag = 0;
        for (auto corner: corners) {
            int mask = corner.second;
            if (mask==0b0001 || mask==0b0010 || mask==0b0100 || mask==0b1000) {
                if (flag & mask)
                    return false;
                flag |= mask;
            }
            else if (mask==0b0101 || mask==0b0110 || mask==0b1010 || mask==0b1001)
                continue;
            else if (mask==0b1111)
                continue;
            else
                return false;
        }
        return true;;
    }
};

int main() {
    vector<vector<int>> rectangles = {{0,0,1,1},{0,2,1,3},{1,1,2,2},{2,0,3,1},{2,2,3,3},{1,0,2,3},{0,1,3,2}};
    Solution solution;
    solution.isRectangleCover(rectangles);
    return 0;
}
