#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t)
{
    if ( strlen(s) != strlen(t) )
        return false;
    char mapA[128], mapB[128];
    memset(mapA, 0, sizeof(mapA));
    memset(mapB, 0, sizeof(mapB));
    for ( int i = 0; s[i] != '\0'; i++ )
    {
        if ( !mapA[(int)s[i]] && !mapB[(int)t[i]] )
        {
            mapA[(int)s[i]] = t[i];
            mapB[(int)t[i]] = s[i];
        }
        else if ( mapA[(int)s[i]] != t[i] || mapB[(int)t[i]] != s[i] )
            return false;
    }
    return true;
}

int main()
{
    return 0;
}
