#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int flag[128];
    int maxlen = 0, len = 0;
    int i, j;
    memset(flag, -1, sizeof(flag));
    for ( i = 0; s[i] != '\0'; i++ )
    {
        if ( flag[(int)s[i]] == -1 )
        {
            len++;
            flag[(int)s[i]] = i;
        }
        else
        {
            for ( j = i-len; s[j] != s[i]; j++ )
                flag[(int)s[j]] = -1;
            flag[(int)s[j]] = i;
            len = i-j;
        }
        if ( maxlen < len )
            maxlen = len;
    }
    return maxlen;
}

int main()
{
    printf("%d\n", lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstu"));
    return 0;
}
