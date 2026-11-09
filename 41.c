/* Write a C program to perform basic string operations such as finding string
length, copying and concatenation.*/


#include <stdio.h>
#include <string.h>
int main() {
    char str1[100], str2[50], copyStr[100];
    printf("Enter first string : ");
    scanf("%49s", str1);
    printf("Enter second string: ");
    scanf("%49s", str2);
    printf("Length of first string (strlen)  = %lu\n", (unsigned long)strlen(str1));
    printf("Length of second string (strlen) = %lu\n", (unsigned long)strlen(str2));
    strcpy(copyStr, str1);
    printf("Copied string (strcpy)           = %s\n", copyStr);
    strcat(str1, str2);
    printf("Concatenated string (strcat)     = %s\n", str1);
    return 0;
}