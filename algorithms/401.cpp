#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector< vector<string> > hours = {{"0"},
                                      {"1", "2", "4", "8"},
                                      {"3", "5", "6", "9", "10"},
                                      {"7", "11"}};
    vector< vector<string> > mins = {{"00"},
                                     {"01", "02", "04", "08", "16", "32"},
                                     {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"},
                                     {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"},
                                     {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"},
                                     {"31", "47", "55", "59"}};
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int i = 0; i <= num; i++) {
            int j = num - i;
            if (i >= hours.size() || j >= mins.size()) continue;
            for (auto str1: hours[i])
                for (auto str2: mins[j])
                    result.push_back(str1 + ":" + str2);
        }
        return result;
    }
};

int main() {
    Solution solution;
    solution.readBinaryWatch(4);
    return 0;
}
