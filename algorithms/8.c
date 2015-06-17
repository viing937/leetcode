#include <stdio.h>
#include <string.h>

int myAtoi(char* str)
{
    if ( !str || str[0]=='\0' )
        return 0;
    int i = 0;
    int sign = 0, overflow = 0;
    unsigned int result = 0;
    while ( str[i] != '\0' && str[i] == ' ' )
        i++;
    if ( str[i] != '\0' && (str[i] == '+'||str[i] == '-') )
        if ( str[i++] == '-' )
            sign = 1;
    while ( str[i] != '\0' )
    {
        if ( str[i] >= '0' && str[i] <= '9' )
        {
            if ( result > 4294967296/10 )
            {
                overflow = 1;
                break;
            }
            result = result*10+str[i]-'0';
        }
        else
            break;
        i++;
    }
    if ( sign )
    {
        if ( overflow || result > 2147483648 )
            return -2147483648;
        else
            return -(int)result;
    }
    else
    {
        if ( overflow || result > 2147483647 )
            return 2147483647;
        else
            return (int)result;
    }
}

int main()
{
    printf("%d\n", myAtoi("2147483647"));
    return 0;
}
