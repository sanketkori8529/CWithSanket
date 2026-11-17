#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    int pin = 1234, enteredPin, attempts = 3;
    int choice, newPin;
    float balance = 100000.00;

    printf("====================================\n");
    printf("        WELCOME TO C BANK ATM       \n");
    printf("====================================\n");

    // PIN Verification
    while (attempts > 0) {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            printf("\nLogin Successful!\n");
            break;
        } else {
            attempts--;
            printf("Incorrect PIN. Attempts left: %d\n", attempts);
            if (attempts == 0) {
                printf("Card blocked due to too many failed attempts.\n");
                return 0;
            }
        }
    }

    // Main Menu Loop
    while (1) {
        printf("\n------------------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance = depositMoney(balance);
                break;

            case 3:
                balance = withdrawMoney(balance);
                break;

            case 4:
                printf("\nEnter current PIN: ");
                scanf("%d", &enteredPin);
                if (enteredPin == pin) {
                    printf("Enter new 4-digit PIN: ");
                    scanf("%d", &newPin);
                    if (newPin >= 1000 && newPin <= 9999) {
                        pin = newPin;
                        printf("PIN updated successfully!\n");
                    } else {
                        printf("Invalid PIN. Must be 4 digits.\n");
                    }
                } else {
                    printf("Incorrect current PIN.\n");
                }
                break;

            case 5:
                printf("\nThank you for using C Bank ATM. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid option! Please choose between 1 and 5.\n");
        }
    }

    return 0;
}

void checkBalance(float balance) {
    printf("\nCurrent Balance: Rs. %.2f\n", balance);
}

float depositMoney(float balance) {
    float amount;
    printf("\nEnter amount to deposit: Rs. ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Rs. %.2f deposited successfully!\n", amount);
        printf("Updated Balance: Rs. %.2f\n", balance);
    } else {
        printf("Invalid amount! Enter a positive value.\n");
    }
    return balance;
}

float withdrawMoney(float balance) {
    float amount;
    printf("\nEnter amount to withdraw: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Enter a positive value.\n");
    } else if (amount > balance) {
        printf("Insufficient balance!\n");
    } else {
        balance -= amount;
        printf("Please collect your cash: Rs. %.2f\n", amount);
        printf("Remaining Balance: Rs. %.2f\n", balance);
    }
    return balance;
}