/*Write a program to calculate simple interest (SI)
  where principal amount, rate of interest, time is taken from user. SI=(P*R*T)/100 */

#include <stdio.h>

int main() {
    float principal, rate, time, si;

    // Input values from the user
    printf("Enter the Principal amount (in Rs.): ");
    scanf("%f", &principal);

    printf("Enter the Rate of interest (per annum): ");
    scanf("%f", &rate);

    printf("Enter the Time period (in years): ");
    scanf("%f", &time);

    // Calculate Simple Interest
    si = (principal * rate * time) / 100;

    // Print the result up to 2 decimal places
    printf("Simple Interest = Rs. %.2f\n", si);

    return 0;
}