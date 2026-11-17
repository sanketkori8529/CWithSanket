// Input array of N numbers; find max and min.

#include <stdio.h>
int main() {
    int n, i, arr[100], max, min;
    printf("Enter number of elements (N): ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    max = min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);
    return 0;
}