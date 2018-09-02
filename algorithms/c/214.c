#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindromic(int l, int r, char *s)
{
    int i;
    for ( i = 0; l+i <= r-i; i++ )
        if ( s[l+i] != s[r-i] )
            return 0;
    return 1;
}

char* shortestPalindrome(char* s)
{
    int i;
    int len = strlen(s);
    int l = 0, r = len-1;
    while ( !isPalindromic(l, r, s) )
        r--;
    char *ans = (char *)malloc(sizeof(char)*(len*2+l-r));
    int index = 0;
    for ( i = len-1; i > r; i-- )
        ans[index++] = s[i];
    for ( i = l; i < len; i++ )
        ans[index++] = s[i];
    ans[index] = '\0';
    return ans;
}

int main()
{
    char *s = shortestPalindrome("");
    printf("%s\n", s);
    free(s);
    return 0;
}
