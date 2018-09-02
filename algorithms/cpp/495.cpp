#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        if (timeSeries.size() == 0 || duration == 0)
            return 0;
        int result = 0, start = timeSeries[0];
        for (int i = 1; i < timeSeries.size(); i++) {
            result += min(timeSeries[i]-start, duration);
            start = timeSeries[i];
        }
        result += duration;
        return result;
    }
};

int main() {
    return 0;
}
