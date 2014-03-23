#ifndef _STRING_UTILITIES_H
#define _STRING_UTILITIES_H

#define RESET 0
#define NEXT  1

#define BUFF_LENGTH 100

#define ELEMENT_LENGTH 10

void replace_non_alphanumeric(char *start, int number_of_bytes, char replace_with);

int getElement(char *src, char *dest, int argument);



#endif

