#include <stdio.h>

void reverse(char *start, char *end)
{
    while ( end > start )
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++, end--;
    }
}

void trim(char *str)
{
    int count = 0;
    int flag = 1;
    for ( int i = 0; str[i] != '\0'; i++ )
    {
        if ( str[i] != ' ' )
        {
            str[count++] = str[i];
            flag = 0;
        }
        else if ( !flag )
        {
            str[count++] = str[i];
            flag = 1;
        }
    }
    if ( count >= 1 && str[count-1] == ' ' )
        str[count-1] = '\0';
    else
        str[count] = '\0';
}

void reverseWords(char *s)
{
    trim(s);
    char *temp = s, *prev = s;
    while ( *temp != '\0' )
    {
        temp++;
        if ( *temp == ' ' || *temp == '\0' )
        {
            reverse(prev, temp-1);
            prev = temp+1;
        }
    }
    reverse(s, temp-1);
}

int main()
{
    return 0;
}
