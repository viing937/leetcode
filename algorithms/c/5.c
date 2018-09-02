#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int adjust_odd(int k, char str[])
{
    int i;
    for ( i = 0; k-i >= 0 && str[k+i] != '\0'; i++ )
        if ( str[k-i] != str[k+i] )
            break;
    return i-1;
}

int adjust_even(int k, char str[])
{
    int i;
    for ( i = 0; k-1-i >= 0 && str[k+i] != '\0'; i++ )
        if ( str[k-1-i] != str[k+i] )
            break;
    return i-1;
}

char* longestPalindrome(char* s)
{
    int l = 0, r = 0;
    int i;
    for ( i = 0; s[i] != '\0'; i++ )
    {
        int len;
        len = adjust_odd(i, s);
        if ( len*2 > r-l )
            l = i-len, r = i+len;
        if ( i >= 1 && s[i-1] == s[i] )
        {
            len = adjust_even(i, s);
            if ( len*2+1 > r-l )
                l = i-1-len, r = i+len;
        }
    }
    char *ans = (char *)malloc(sizeof(char)*(r-l+2));
    for ( i = 0; l+i <= r; i++ )
        ans[i] = s[l+i];
    ans[i] = '\0';
    return ans;
}

int main()
{
    char *subStr = longestPalindrome("asdfeefdfsgr");
    printf("%s\n", subStr);
    free(subStr);
    return 0;
}
