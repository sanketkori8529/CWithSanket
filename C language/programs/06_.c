// C program to Convert Celsius (Centigrade) temperature to Fahrenheit

#include <stdio.h>

int main()
{
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (9.0 / 5.0) * celsius + 32;

    printf("Temperature in Fahrenheit = %.2f", fahrenheit);

    return 0;
}