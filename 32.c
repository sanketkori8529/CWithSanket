// reverse a string.

#include <stdio.h>
#include <string.h>
int main() {
    char str[100], temp;
    int left, right;
    printf("Enter a string: ");
    scanf("%99s", str);
    left = 0;
    right = strlen(str) - 1;
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    printf("Reversed string: %s\n", str);
    return 0;
}