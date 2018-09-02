#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
    int numV, numC;
    unordered_map<long double, int> hash;
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();

        int result = 0;

        for (int i = 0; i < n; i++) {
            numV = numC = 0;
            hash.clear();
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    numC += 1;
                else if (points[i].x == points[j].x)
                    numV += 1;
                else {
                    long double slope = (long double)(points[i].y-points[j].y)/(points[i].x-points[j].x);
                    if (hash.find(slope) == hash.end())
                        hash[slope] = 0;
                    hash[slope] += 1;
                }
            }
            for (auto it = hash.begin(); it != hash.end(); ++it)
                numV = max(numV, it->second);
            result = max(result, 1 + numC + numV);
        }
        return result;
    }
};

int main() {
    return 0;
}
