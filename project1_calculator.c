#include <stdio.h>
#include <math.h>

// Function declarations
void basicCalc();
void binaryConverter();
void unitConverter();
void matrixAddition();
void simpleInterestAndBMI();

int main() {
    int ch;

    do {
        printf("\n==========================================\n");
        printf("      ALL-IN-ONE CALCULATOR PROJECT       \n");
        printf("==========================================\n");
        printf("1. Basic & Scientific Calculator\n");
        printf("2. Decimal to Binary Converter\n");
        printf("3. Currency & Temperature Converter\n");
        printf("4. 2x2 Matrix Addition\n");
        printf("5. Simple Interest & BMI Calculator\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                basicCalc();
                break;
            case 2:
                binaryConverter();
                break;
            case 3:
                unitConverter();
                break;
            case 4:
                matrixAddition();
                break;
            case 5:
                simpleInterestAndBMI();
                break;
            case 0:
                printf("Thank you for using the calculator!\n");
                break;
            default:
                printf("Wrong choice! Please try again.\n");
        }
    } while (ch != 0);

    return 0;
}

// Part 1: Basic & Scientific Calculator
void basicCalc() {
    int op;
    float a, b, ans;

    printf("\n--- Basic Calculator ---\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power (a^b)\n6. Square Root\n");
    printf("Enter operation number: ");
    scanf("%d", &op);

    if (op >= 1 && op <= 5) {
        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);
    } else if (op == 6) {
        printf("Enter number: ");
        scanf("%f", &a);
    }

    if (op == 1) {
        ans = a + b;
        printf("Sum = %.2f\n", ans);
    } else if (op == 2) {
        ans = a - b;
        printf("Difference = %.2f\n", ans);
    } else if (op == 3) {
        ans = a * b;
        printf("Product = %.2f\n", ans);
    } else if (op == 4) {
        if (b != 0) {
            ans = a / b;
            printf("Division = %.2f\n", ans);
        } else {
            printf("Cannot divide by zero!\n");
        }
    } else if (op == 5) {
        ans = pow(a, b);
        printf("Power = %.2f\n", ans);
    } else if (op == 6) {
        ans = sqrt(a);
        printf("Square Root = %.2f\n", ans);
    } else {
        printf("Invalid choice!\n");
    }
}

// Part 2: Decimal to Binary using 1D Array
void binaryConverter() {
    int n, rem[20], i = 0, j;

    printf("\n--- Decimal to Binary Converter ---\n");
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Binary = 0\n");
        return;
    }

    while (n > 0) {
        rem[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Binary = ");
    for (j = i - 1; j >= 0; j--) {
        printf("%d", rem[j]);
    }
    printf("\n");
}

// Part 3: Unit and Currency Converter
void unitConverter() {
    int ch;
    float val, res;

    printf("\n--- Unit Converter ---\n");
    printf("1. Rupees (INR) to Dollars (USD)\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Kilometre to Metre\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("Enter amount in Rupees: ");
        scanf("%f", &val);
        res = val / 84.0;
        printf("Amount in USD = %.2f\n", res);
    } else if (ch == 2) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &val);
        res = (val * 9 / 5) + 32;
        printf("Temperature in Fahrenheit = %.2f\n", res);
    } else if (ch == 3) {
        printf("Enter distance in Km: ");
        scanf("%f", &val);
        res = val * 1000;
        printf("Distance in Metres = %.2f m\n", res);
    } else {
        printf("Invalid choice!\n");
    }
}

// Part 4: 2x2 Matrix Addition using 2D Array
void matrixAddition() {
    int a[2][2], b[2][2], sum[2][2];
    int i, j;

    printf("\n--- 2x2 Matrix Addition ---\n");
    printf("Enter 4 numbers for Matrix A:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter 4 numbers for Matrix B:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Adding both matrices
    printf("Sum of Matrix A and B is:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
}

// Part 5: Simple Interest & BMI Calculator
void simpleInterestAndBMI() {
    int ch;
    float p, r, t, si, weight, height, bmi;

    printf("\n--- Finance & Health ---\n");
    printf("1. Simple Interest Calculator\n");
    printf("2. BMI Calculator\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("Enter Principal, Rate, and Time (in years): ");
        scanf("%f %f %f", &p, &r, &t);
        si = (p * r * t) / 100;
        printf("Simple Interest = Rs. %.2f\n", si);
        printf("Total Amount = Rs. %.2f\n", p + si);
    } else if (ch == 2) {
        printf("Enter Weight (in kg): ");
        scanf("%f", &weight);
        printf("Enter Height (in metres, e.g. 1.70): ");
        scanf("%f", &height);
        bmi = weight / (height * height);
        printf("Your BMI is = %.2f\n", bmi);
    } else {
        printf("Invalid choice!\n");
    }
}