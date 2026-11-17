//File Handling – Write and Read a File

#include <stdio.h>

int main()
{
    FILE *fp;
    char text[100];

    fp = fopen("data.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    printf("Enter text: ");
    scanf(" %[^\n]", text);

    fprintf(fp, "%s", text);
    fclose(fp);

    fp = fopen("data.txt", "r");

    fgets(text, 100, fp);

    printf("File content: %s", text);

    fclose(fp);

    return 0;
}