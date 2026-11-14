#include <stdio.h>

int main() {
    float radius, area, circumference;
    const float PI = 3.14159;

    // Input radius from keyboard
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Calculate area and circumference
    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    // Print results up to 2 decimal places
    printf("Area of the circle = %.2f\n", area);
    printf("Circumference of the circle = %.2f\n", circumference);

    return 0;
}