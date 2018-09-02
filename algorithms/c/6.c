#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    if ( numRows == 1 )
        return s;
    int i, j, k;
    int len = strlen(s);
    char *ans = (char *)malloc(sizeof(char)*(len+1));
    int index = 0;
    for ( i = 0; i < len; i += 2*numRows-2 )
        ans[index++] = s[i];
    for ( i = 1; i < numRows-1; i++ )
    {
        k = i;
        for ( j = 0; k < len; j++ )
        {
            ans[index++] = s[k];
            if ( j%2 )
                k += 2*i;
            else
                k += 2*numRows-2-2*i;
        }
    }
    for ( i = numRows-1; i < len; i += 2*numRows-2 )
        ans[index++] = s[i];
    ans[index] = '\0';
    return ans;
}

int main()
{
    char *ans = convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.", 3);
    printf("%s\n", ans);
    free(ans);
    return 0;
}
