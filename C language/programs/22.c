//Compute average of array.

#include <stdio.h>
int main() {
    int n, i, arr[100], sum = 0;
    float avg;
    printf("Enter number of elements (N): ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = (float)sum / n;
    printf("Sum = %d, Average = %.2f\n", sum, avg);
    return 0;
}