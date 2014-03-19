#include "string_utilities.h"

void replace_non_alphanumeric(char *start, int number_of_bytes, char replace_with)
{
    int i=0;
    while(i<number_of_bytes)
    {
        if( !( (start[i]>='a' && start[i]<='z') || (start[i]>='A' && start[i]<='Z') || (start[i]>='0' && start[i]<='9') ) )
        {
           start[i]=replace_with;
        }
        i++;
    }
}

void getElement(char *src, char *dest, int argument, int src_length)
{
    static char *ptr;
    *dest = '\0';
    if(argument == RESET)
    {
        ptr = src;
    }

    while(*ptr == '\0')
    {
        ptr++;
        if( ptr-src > src_length )
        {
            return;
        }
    }
    while(*ptr != '\0')
    {
        *dest = *ptr;
        dest++;
        ptr++;
        if( ptr-src > src_length )
        {
            return;
        }
    }
    *dest = '\0';
}