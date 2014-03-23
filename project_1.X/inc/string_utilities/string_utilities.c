#include "string_utilities.h"

char buffer[BUFF_LENGTH];

char element[ELEMENT_LENGTH];

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

int getElement(char *src, char *dest, int argument)
{
    static char *ptr;
    char *dest_start = dest;
    *dest = '\0';
    if(argument == RESET)
    {
        ptr = src;
    }

    while(*ptr == '\0')
    {
        ptr++;
        if( ptr-src > BUFF_LENGTH )
        {
            return -1;
        }
    }
    while(*ptr != '\0')
    {
        *dest = *ptr;
        dest++;
        ptr++;
        if( (ptr-src > BUFF_LENGTH) || (dest - dest_start)>=ELEMENT_LENGTH)
        {
            return -2;
        }
    }
    *dest = '\0';
    return 0;
}