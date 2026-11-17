#include <stdio.h>

// Global variables so balance and booked seats are remembered across function calls
float balance = 5000.0; // Starting Bank Balance Rs. 5000
int pin = 1234;         // Default ATM PIN
int seats[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // 0 = Empty, 1 = Booked (Seats 1 to 10)

// Function Declarations
void bankATM();
void cafeBilling();
void busBooking();

int main() {
    int ch;

    do {
        printf("\n================================================\n");
        printf("   COMMERCIAL HUB: ATM, CAFE & TICKET BOOKING   \n");
        printf("================================================\n");
        printf("1. Bank ATM Simulator\n");
        printf("2. College Cafe Billing System\n");
        printf("3. Bus Seat Reservation System\n");
        printf("0. Exit Program\n");
        printf("------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                bankATM();
                break;
            case 2:
                cafeBilling();
                break;
            case 3:
                busBooking();
                break;
            case 0:
                printf("Thank you for using Commercial Hub!\n");
                break;
            default:
                printf("Invalid choice! Please select 0 to 3.\n");
        }
    } while (ch != 0);

    return 0;
}

// ==========================================================
// PART 1: BANK ATM SIMULATOR
// Concepts: Global variable update, PIN check, nested menu
// ==========================================================
void bankATM() {
    int enteredPin, atmChoice;
    float amount;

    printf("\n--- Welcome to Bank ATM ---\n");
    printf("Enter your 4-digit PIN (Default is 1234): ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Wrong PIN! Access Denied.\n");
        return;
    }

    do {
        printf("\n--- ATM Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &atmChoice);

        if (atmChoice == 1) {
            printf("Your Current Balance is: Rs. %.2f\n", balance);
        } else if (atmChoice == 2) {
            printf("Enter amount to deposit: Rs. ");
            scanf("%f", &amount);
            if (amount > 0) {
                balance = balance + amount;
                printf("Amount Deposited! New Balance = Rs. %.2f\n", balance);
            } else {
                printf("Invalid amount!\n");
            }
        } else if (atmChoice == 3) {
            printf("Enter amount to withdraw: Rs. ");
            scanf("%f", &amount);
            if (amount > balance) {
                printf("Insufficient Balance! You only have Rs. %.2f\n", balance);
            } else if (amount <= 0) {
                printf("Invalid amount!\n");
            } else {
                balance = balance - amount;
                printf("Please collect your cash!\n");
                printf("Remaining Balance = Rs. %.2f\n", balance);
            }
        }
    } while (atmChoice != 0);
}

// ==========================================================
// PART 2: COLLEGE CAFE BILLING SYSTEM
// Concepts: Running total accumulator, percentage & GST math
// ==========================================================
void cafeBilling() {
    int item, qty, more = 1;
    float subtotal = 0, gst, discount = 0, finalBill;

    printf("\n--- Welcome to B.Tech Canteen ---\n");
    printf("Item No\t\tItem Name\tPrice\n");
    printf("1.\t\tSamosa\t\tRs. 15\n");
    printf("2.\t\tMasala Chai\tRs. 10\n");
    printf("3.\t\tVeg Maggi\tRs. 40\n");
    printf("4.\t\tCold Coffee\tRs. 60\n");
    printf("5.\t\tPaneer Patties\tRs. 25\n");

    while (more == 1) {
        printf("\nEnter Item Number (1-5): ");
        scanf("%d", &item);
        printf("Enter Quantity: ");
        scanf("%d", &qty);

        if (item == 1) {
            subtotal = subtotal + (15 * qty);
        } else if (item == 2) {
            subtotal = subtotal + (10 * qty);
        } else if (item == 3) {
            subtotal = subtotal + (40 * qty);
        } else if (item == 4) {
            subtotal = subtotal + (60 * qty);
        } else if (item == 5) {
            subtotal = subtotal + (25 * qty);
        } else {
            printf("Invalid Item Number!\n");
        }

        printf("Do you want to add more items? (1 = Yes, 0 = No): ");
        scanf("%d", &more);
    }

    // 10% Discount if bill is above Rs. 200
    if (subtotal >= 200) {
        discount = (subtotal * 10) / 100;
    }

    // 5% GST calculation
    gst = ((subtotal - discount) * 5) / 100;
    finalBill = (subtotal - discount) + gst;

    printf("\n================ FINAL CAFE BILL ================\n");
    printf("Subtotal Amount      : Rs. %.2f\n", subtotal);
    printf("Discount (10%% > 200) : Rs. %.2f\n", discount);
    printf("GST (5%%)             : Rs. %.2f\n", gst);
    printf("-------------------------------------------------\n");
    printf("Net Payable Amount   : Rs. %.2f\n", finalBill);
    printf("=================================================\n");
}

// ==========================================================
// PART 3: BUS SEAT RESERVATION SYSTEM
// Concepts: 1D Array status tracking (0 = Empty, 1 = Booked)
// ==========================================================
void busBooking() {
    int busChoice, seatNo, i;

    do {
        printf("\n--- UPSRTC Bus Ticket Booking ---\n");
        printf("1. View Seat Layout (10 Seats)\n");
        printf("2. Book a Seat (Rs. 250 per ticket)\n");
        printf("3. Cancel a Seat\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &busChoice);

        if (busChoice == 1) {
            printf("\n--- Current Seat Status (0 = Available, 1 = Booked) ---\n");
            for (i = 1; i <= 10; i++) {
                printf("Seat %d: [%d]\t", i, seats[i]);
                if (i % 2 == 0) {
                    printf("\n"); // Print 2 seats per row like a real bus
                }
            }
        } else if (busChoice == 2) {
            printf("Enter Seat Number to book (1 to 10): ");
            scanf("%d", &seatNo);

            if (seatNo < 1 || seatNo > 10) {
                printf("Invalid seat number! Please enter between 1 and 10.\n");
            } else if (seats[seatNo] == 1) {
                printf("Sorry! Seat %d is already booked.\n", seatNo);
            } else {
                seats[seatNo] = 1; // Mark seat as booked
                printf("Success! Seat %d is booked.\n", seatNo);
                printf("Ticket Fare = Rs. 250\n");
            }
        } else if (busChoice == 3) {
            printf("Enter Seat Number to cancel (1 to 10): ");
            scanf("%d", &seatNo);

            if (seatNo < 1 || seatNo > 10) {
                printf("Invalid seat number!\n");
            } else if (seats[seatNo] == 0) {
                printf("Seat %d is already empty!\n", seatNo);
            } else {
                seats[seatNo] = 0; // Mark seat as empty again
                printf("Ticket Cancelled! Seat %d is now available.\n", seatNo);
            }
        }
    } while (busChoice != 0);
}