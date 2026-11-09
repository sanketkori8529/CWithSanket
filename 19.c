// Concept of gets and puts


#include <stdio.h>

int main()
{
    char name[20];

    printf("Enter your name: ");
    gets(name);

    printf("Name = ");
    puts(name);

    return 0;
}