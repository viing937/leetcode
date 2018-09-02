#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int MAX_STEP = 6;
    string shrink(string s) {
        while (true) {
            int start = 0, cnt = 1;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] == s[start])
                    cnt += 1;
                else if (cnt >= 3)
                    break;
                else {
                    start = i;
                    cnt = 1;
                }
            }
            if (cnt >= 3)
                s = s.substr(0, start) + s.substr(start+cnt);
            else
                return s;
        }
    }
    int helper(string board, string hand) {
        if (board.size() == 0) return 0;
        if (hand.size() == 0) return MAX_STEP;
        int result = MAX_STEP;
        for (int i = 0; i < hand.size(); i++) {
            int j = 0;
            while (j < board.size()) {
                int k = board.find(hand[i], j);
                if (k == string::npos) break;
                if (k+1 < board.size() && board[k] == board[k+1]) {
                    string nextBoard = shrink(board.substr(0, k) + board.substr(k+2));
                    string nextHand = hand.substr(0, i) + hand.substr(i+1);
                    if (nextBoard.size() == 0) return 1;
                    result = min(result, helper(nextBoard, nextHand) + 1);
                }
                else if (i > 0 && hand[i] == hand[i-1]) {
                    string nextBoard = shrink(board.substr(0, k) + board.substr(k+1));
                    string nextHand = hand.substr(0, i-1) + hand.substr(i+1);
                    if (nextBoard.size() == 0) return 2;
                    result = min(result, helper(nextBoard, nextHand) + 2);
                }
                j = k+1;
            }
        }
        return result;
    }
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int result = helper(board, hand);
        return result>=MAX_STEP ? -1 : result;
    }
};

int main() {
    return 0;
}
