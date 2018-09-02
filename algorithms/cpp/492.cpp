#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area%w != 0)
            w -= 1;
        vector<int> result = {area/w, w};
        return result;
    }
};

int main() {
    return 0;
}
