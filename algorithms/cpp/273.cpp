#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    unordered_map<int, string> dict = { {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
                                        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
                                        {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
                                        {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
                                        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},
                                        {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"} };
    string tranlate(int num, const string &suffix)
    {
        if ( num == 0 ) return "";
        string result;
        int h = num/100;
        if ( h )
            result += dict[h] + " " + dict[100] + " ";
        num %= 100;
        int c = num/10;
        if ( c )
        {
            if ( c == 1 )
                result += dict[num] + " ";
            else
                result += dict[c*10] + " ";
        }
        num %= 10;
        if ( num && c != 1 )
            result += dict[num] + " ";
        return result + suffix + " ";
    }
public:
    string numberToWords(int num)
    {
        if ( num == 0 )
            return dict[num];
        string result;
        int b = num / 1000000000;
        result += tranlate(b, "Billion");
        num %= 1000000000;
        int m = num / 1000000;
        result += tranlate(m, "Million");
        num %= 1000000;
        int k = num / 1000;
        result += tranlate(k, "Thousand");
        num %= 1000;
        result += tranlate(num, "");
        while ( result[result.size()-1] == ' ' )
            result.erase(result.end()-1);
        return result;
    }
};

int main()
{
    return 0;
}
