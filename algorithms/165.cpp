#include <iostream>
#include <string>
using namespace std;

class Solution
{
private:
    int compareString(string str1, string str2)
    {
        int num1 = stoi(str1), num2 = stoi(str2);
        if ( num1 < num2 )
            return -1;
        else if ( num1 > num2 )
            return 1;
        else
            return 0;
    }
public:
    int compareVersion(string version1, string version2)
    {
        int aDot = version1.find_first_of('.');
        int bDot = version2.find_first_of('.');
        if ( aDot != -1 && bDot != -1 )
        {
            int cmp = compareString(version1.substr(0, aDot), version2.substr(0, bDot));
            if ( cmp == 0 )
                return compareVersion(version1.substr(aDot+1, version1.size()-aDot-1), version2.substr(bDot+1, version2.size()-bDot-1));
            else
                return cmp;
        }
        else if ( aDot != -1 )
        {
            int cmp = compareString(version1.substr(0, aDot), version2);
            if ( cmp == 0 )
                return compareVersion(version1.substr(aDot+1, version1.size()-aDot-1), "0");
            else
                return cmp;
        }
        else if ( bDot != -1 )
        {
            int cmp = compareString(version1, version2.substr(0, bDot));
            if ( cmp == 0 )
                return compareVersion("0", version2.substr(bDot+1, version2.size()-bDot-1));
            else
                return cmp;
        }
        else
        {
            int cmp = compareString(version1, version2);
            return cmp;
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.compareVersion("1.0", "1.0") << endl;
    return 0;
}
