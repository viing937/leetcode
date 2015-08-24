#include <iostream>
#include <list>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int len = path.size();
        list<string> domain;
        for ( int i = 0; i < len; ++i )
        {
            if ( path[i] == '/' )
                continue;
            if ( path[i] == '.' && (i+1 >= len || path[i+1] == '/') )
                continue;
            if ( path[i] == '.' && path[i+1] == '.' && (i+2 >= len || path[i+2] == '/') )
            {
                i += 1;
                if ( !domain.empty() )
                    domain.pop_back();
                continue;
            }
            int cnt = 1;
            while ( path[i+cnt] != '/' )
                cnt += 1;
            domain.push_back(path.substr(i, cnt));
            i += cnt-1;
        }
        if ( domain.empty() )
            return "/";
        string result;
        for ( auto it = domain.begin(); it != domain.end(); ++it )
            result += "/" + *it;
        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.simplifyPath("/a/./b/../../c/") << endl;
    return 0;
}
