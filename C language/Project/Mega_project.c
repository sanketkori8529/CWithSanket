#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Global variables for Shared State
float bankBalance = 5000.0f;

// Structure for Student Record
struct Student {
    int roll;
    char name[30];
    float marks;
};

// Function Prototypes for all 10 Mini-Projects
void runCalculator();
void runBinaryConverter();
void runNumberGuessing();
void runRockPaperScissors();
void runStudentManagement();
void runBankATM();
void runCalendarChecker();
void runFinanceAndBMI();
void runHandCricket();
void runCafeBilling();

int main() {
    int choice;
    srand(time(0)); // Seed random number generator

    do {
        printf("\n==================================================\n");
        printf("           MEGA C PROJECT: MAIN MENU              \n");
        printf("==================================================\n");
        printf(" 1. Standard Calculator\n");
        printf(" 2. Decimal to Binary Converter\n");
        printf(" 3. Number Guessing Game\n");
        printf(" 4. Rock, Paper, Scissors\n");
        printf(" 5. Student Record Management (File Handling)\n");
        printf(" 6. Bank ATM Simulator\n");
        printf(" 7. Leap Year & Days Calculator\n");
        printf(" 8. Simple Interest & BMI Calculator\n");
        printf(" 9. Hand Cricket Game\n");
        printf("10. Cafe Billing System\n");
        printf(" 0. Exit Mega Program\n");
        printf("--------------------------------------------------\n");
        printf("Enter your choice (0-10): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: runCalculator(); break;
            case 2: runBinaryConverter(); break;
            case 3: runNumberGuessing(); break;
            case 4: runRockPaperScissors(); break;
            case 5: runStudentManagement(); break;
            case 6: runBankATM(); break;
            case 7: runCalendarChecker(); break;
            case 8: runFinanceAndBMI(); break;
            case 9: runHandCricket(); break;
            case 10: runCafeBilling(); break;
            case 0: printf("\nExiting Mega Project. Good luck with your practical!\n"); break;
            default: printf("\nInvalid choice! Please select between 0 and 10.\n");
        }
    } while (choice != 0);

    return 0;
}

// 1. Standard Calculator
void runCalculator() {
    int op;
    float a, b;
    printf("\n--- 1. Standard Calculator ---\n");
    printf("1. Add (+)  2. Subtract (-)  3. Multiply (*)  4. Divide (/)\n");
    printf("Enter choice: ");
    scanf("%d", &op);
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch (op) {
        case 1: printf("Result = %.2f\n", a + b); break;
        case 2: printf("Result = %.2f\n", a - b); break;
        case 3: printf("Result = %.2f\n", a * b); break;
        case 4: 
            if (b != 0) printf("Result = %.2f\n", a / b);
            else printf("Error: Division by zero!\n");
            break;
        default: printf("Invalid operator!\n");
    }
}

// 2. Decimal to Binary Converter
void runBinaryConverter() {
    int n, rem[20], i = 0, j;
    printf("\n--- 2. Decimal to Binary Converter ---\n");
    printf("Enter a positive decimal number: ");
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

// 3. Number Guessing Game
void runNumberGuessing() {
    int secret = (rand() % 50) + 1, guess, attempts = 0;
    printf("\n--- 3. Number Guessing Game (1-50) ---\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess > secret) printf("Too High!\n");
        else if (guess < secret) printf("Too Low!\n");
        else printf("Correct! You found it in %d attempts.\n", attempts);
    } while (guess != secret);
}

// 4. Rock, Paper, Scissors
void runRockPaperScissors() {
    int user, comp;
    printf("\n--- 4. Rock, Paper, Scissors ---\n");
    printf("1 = Rock, 2 = Paper, 3 = Scissors\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &user);

    comp = (rand() % 3) + 1;
    printf("Computer chose: %d\n", comp);

    if (user == comp) printf("Match Draw!\n");
    else if ((user == 1 && comp == 3) || (user == 2 && comp == 1) || (user == 3 && comp == 2))
        printf("You Win!\n");
    else
        printf("Computer Wins!\n");
}

// 5. Student Record Management
void runStudentManagement() {
    int ch;
    struct Student s;
    FILE *fp;

    printf("\n--- 5. Student Record Management ---\n");
    printf("1. Add Record  2. View Records\nChoice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        fp = fopen("students.txt", "a");
        if (fp == NULL) { printf("File error!\n"); return; }
        printf("Enter Roll No, Name (single word), Marks: ");
        scanf("%d %s %f", &s.roll, s.name, &s.marks);
        fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);
        fclose(fp);
        printf("Saved successfully in students.txt!\n");
    } else if (ch == 2) {
        fp = fopen("students.txt", "r");
        if (fp == NULL) { printf("No student records found!\n"); return; }
        printf("\nRoll\tName\tMarks\n---------------------\n");
        while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
            printf("%d\t%s\t%.2f\n", s.roll, s.name, s.marks);
        }
        fclose(fp);
    }
}

// 6. Bank ATM Simulator
void runBankATM() {
    int ch;
    float amt;
    printf("\n--- 6. Bank ATM Simulator ---\n");
    printf("1. Check Balance  2. Deposit  3. Withdraw\nChoice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("Balance: Rs. %.2f\n", bankBalance);
    } else if (ch == 2) {
        printf("Enter deposit amount: Rs. ");
        scanf("%f", &amt);
        bankBalance += amt;
        printf("New Balance: Rs. %.2f\n", bankBalance);
    } else if (ch == 3) {
        printf("Enter withdrawal amount: Rs. ");
        scanf("%f", &amt);
        if (amt <= bankBalance) {
            bankBalance -= amt;
            printf("Please collect cash. Remaining: Rs. %.2f\n", bankBalance);
        } else {
            printf("Insufficient balance!\n");
        }
    }
}

// 7. Calendar Utility (Leap Year & Month Days)
void runCalendarChecker() {
    int yr, mo;
    printf("\n--- 7. Calendar Utility ---\n");
    printf("Enter year: ");
    scanf("%d", &yr);
    printf("Enter month number (1-12): ");
    scanf("%d", &mo);

    if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
        printf("%d is a Leap Year.\n", yr);
    else
        printf("%d is NOT a Leap Year.\n", yr);

    if (mo == 2) {
        if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
            printf("Month %d has 29 days.\n", mo);
        else
            printf("Month %d has 28 days.\n", mo);
    } else if (mo == 4 || mo == 6 || mo == 9 || mo == 11) {
        printf("Month %d has 30 days.\n", mo);
    } else if (mo >= 1 && mo <= 12) {
        printf("Month %d has 31 days.\n", mo);
    } else {
        printf("Invalid month number!\n");
    }
}

// 8. Finance & Health (Simple Interest & BMI)
void runFinanceAndBMI() {
    int ch;
    printf("\n--- 8. Finance & Health Calculator ---\n");
    printf("1. Simple Interest  2. BMI Calculator\nChoice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        float p, r, t;
        printf("Enter Principal, Rate, Time (years): ");
        scanf("%f %f %f", &p, &r, &t);
        printf("Simple Interest = Rs. %.2f\n", (p * r * t) / 100);
    } else if (ch == 2) {
        float w, h;
        printf("Enter Weight (kg) and Height (meters): ");
        scanf("%f %f", &w, &h);
        printf("BMI = %.2f\n", w / (h * h));
    }
}

// 9. Hand Cricket Game
void runHandCricket() {
    int user, comp, total = 0;
    printf("\n--- 9. Hand Cricket Game ---\n");
    printf("Enter runs (1 to 6). If match with computer, you are OUT!\n");

    while (1) {
        printf("Your shot (1-6): ");
        scanf("%d", &user);
        if (user < 1 || user > 6) continue;
        comp = (rand() % 6) + 1;
        printf("Computer bowled: %d\n", comp);
        if (user == comp) {
            printf("OUT! Total Score = %d runs\n", total);
            break;
        }
        total += user;
        printf("Current Score = %d\n", total);
    }
}

// 10. Cafe Billing System
void runCafeBilling() {
    int item, qty, more = 1;
    float subtotal = 0;
    printf("\n--- 10. College Cafe Billing ---\n");
    printf("1. Samosa (Rs.15)  2. Chai (Rs.10)  3. Maggi (Rs.40)  4. Coffee (Rs.60)\n");

    while (more == 1) {
        printf("Enter item number (1-4) and quantity: ");
        scanf("%d %d", &item, &qty);
        if (item == 1) subtotal += 15 * qty;
        else if (item == 2) subtotal += 10 * qty;
        else if (item == 3) subtotal += 40 * qty;
        else if (item == 4) subtotal += 60 * qty;
        else printf("Invalid item!\n");

        printf("Add more items? (1=Yes, 0=No): ");
        scanf("%d", &more);
    }
    printf("Total Bill Amount = Rs. %.2f\n", subtotal);
}