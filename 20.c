// Linear search in array.

#include <stdio.h>
int main() {
    int n, i, key, found = -1, arr[100];
    printf("Enter number of elements (N): ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }
    if (found != -1)
        printf("Element %d found at index %d (Position %d).\n", key, found, found + 
1);
    else
        printf("Element %d not found in the array.\n", key);
    return 0;
}