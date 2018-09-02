#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s)
{
    int key[26];
    key['I'-'A'] = 1;
    key['V'-'A'] = 5;
    key['X'-'A'] = 10;
    key['L'-'A'] = 50;
    key['C'-'A'] = 100;
    key['D'-'A'] = 500;
    key['M'-'A'] = 1000;
    int len = strlen(s);
    int result = 0, pre, cur = key[s[0]-'A'];
    for ( int i = 1; i < len; i++ )
    {
        pre = key[s[i-1]-'A'];
        cur = key[s[i]-'A'];
        if ( cur <= pre )
            result += pre;
        else
        {
            result += cur-pre;
            if ( i == len-1 )
                cur = 0;
            else
                cur = key[s[i+1]-'A'];
            i++;
        }
    }
    if ( result == 0 )
        return cur;
    else
        return result+cur;
}

int main()
{
    int a = romanToInt("MMMCMXCIX");
    printf("%d\n", a);
    return 0;
}
