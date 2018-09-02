#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
    static bool compare(const Point &a, const Point &b) {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    }
    double cross(const Point &o, const Point &a, const Point &b) {
        return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
    }
    void uniquePoints(vector<Point> &points) {
        int cnt = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i].x != points[cnt-1].x || points[i].y != points[cnt-1].y)
                points[cnt++] = points[i];
        }
        points.resize(cnt);
    }
public:
    vector<Point> outerTrees(vector<Point> &points) {
        sort(points.begin(), points.end(), compare);
        vector<Point> result;
        for (int i = 0; i < points.size(); i++) {
            while (result.size() >= 2 && cross(result[result.size()-2], result.back(), points[i]) < 0)
                result.pop_back();
            result.push_back(points[i]);
        }
        for (int i = points.size()-2, t = result.size()+1; i >= 0; i--) {
            while (result.size() >= t && cross(result[result.size()-2], result.back(), points[i]) < 0)
                result.pop_back();
            result.push_back(points[i]);
        }
        sort(result.begin(), result.end(), compare);
        uniquePoints(result);
        return result;
    }
};

int main() {
    return 0;
}
