/* program to calculate simple interest for a set of values representing principal,
number of years, and rate of interest*/

#include <stdio.h>

int main()
{
    float principal, years, rate, simpleInterest;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter number of years: ");
    scanf("%f", &years);

    printf("Enter rate of interest: ");
    scanf("%f", &rate);

    simpleInterest = (principal * years * rate) / 100;

    printf("Simple Interest = %.2f", simpleInterest);

    return 0;
}