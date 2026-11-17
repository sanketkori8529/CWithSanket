#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Phonebook Contact
struct Contact {
    char name[30];
    char phone[15];
};

// Function Declarations
void calendarChecker();
void phonebookApp();
void wordCounter();
void checkLeapYear();

int main() {
    int ch;

    do {
        printf("\n================================================\n");
        printf("    DESKTOP UTILITY TOOLKIT (PROJECT 5)         \n");
        printf("================================================\n");
        printf("1. Leap Year & Days Calculator (Calendar Utility)\n");
        printf("2. Phonebook Directory (Save & Search Contacts)\n");
        printf("3. File Word, Character & Line Counter\n");
        printf("0. Exit Toolkit\n");
        printf("------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                calendarChecker();
                break;
            case 2:
                phonebookApp();
                break;
            case 3:
                wordCounter();
                break;
            case 0:
                printf("Congratulations! You have completed all 5 C Projects!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 0);

    return 0;
}

// ==========================================================
// PART 1: CALENDAR UTILITY (Leap Year & Days in Month)
// Concepts: Logical operators (&&, ||), conditional checks
// ==========================================================
void calendarChecker() {
    int year, month;

    printf("\n--- Calendar Utility: Leap Year & Month Days ---\n");
    printf("Enter year (e.g., 2026): ");
    scanf("%d", &year);
    printf("Enter month number (1 to 12): ");
    scanf("%d", &month);

    // Leap Year formula taught in AKTU Unit 1
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a Leap Year (Feb has 29 days).\n", year);
    } else {
        printf("%d is NOT a Leap Year (Feb has 28 days).\n", year);
    }

    // Days in specific month
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        printf("Month %d has 31 days.\n", month);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        printf("Month %d has 30 days.\n", month);
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("Month 2 (February) has 29 days.\n");
        } else {
            printf("Month 2 (February) has 28 days.\n");
        }
    } else {
        printf("Invalid month number!\n");
    }
}

// ==========================================================
// PART 2: PHONEBOOK DIRECTORY
// Concepts: Struct, Append file mode ("a"), Read file mode ("r")
// ==========================================================
void phonebookApp() {
    struct Contact c;
    FILE *fp;
    int choice;
    char searchName[30];
    int flag = 0;

    printf("\n--- Phonebook Directory ---\n");
    printf("1. Add New Contact\n");
    printf("2. Search Contact by Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        fp = fopen("phonebook.txt", "a");
        if (fp == NULL) {
            printf("Error opening phonebook file!\n");
            return;
        }

        printf("Enter Name (use underscore for space): ");
        scanf("%s", c.name);
        printf("Enter Phone Number: ");
        scanf("%s", c.phone);

        fprintf(fp, "%s %s\n", c.name, c.phone);
        fclose(fp);
        printf("Contact saved successfully in phonebook.txt!\n");

    } else if (choice == 2) {
        fp = fopen("phonebook.txt", "r");
        if (fp == NULL) {
            printf("No contacts saved yet!\n");
            return;
        }

        printf("Enter Name to search: ");
        scanf("%s", searchName);

        while (fscanf(fp, "%s %s", c.name, c.phone) != EOF) {
            if (strcmp(c.name, searchName) == 0) {
                printf("\nContact Found!\n");
                printf("Name : %s\nPhone: %s\n", c.name, c.phone);
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf("No contact found with name '%s'.\n", searchName);
        }
        fclose(fp);
    }
}

// ==========================================================
// PART 3: FILE WORD, CHARACTER & LINE COUNTER
// Concepts: fgetc(), character parsing, file traversal
// ==========================================================
void wordCounter() {
    FILE *fp;
    char ch;
    int characters = 0, words = 0, lines = 0;
    char filename[30];

    printf("\n--- File Text Analyzer & Counter ---\n");
    printf("Enter filename to analyze (e.g., students.txt or library.txt): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'. Make sure it exists!\n", filename);
        return;
    }

    // Read file character by character using fgetc()
    while ((ch = fgetc(fp)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
            words++; // Newline also marks the end of a word
        } else if (ch == ' ' || ch == '\t') {
            words++;
        }
    }

    // If file has text but doesn't end with a newline, account for the last word
    if (characters > 0) {
        words++;
        lines++;
    }

    fclose(fp);

    printf("\n--- Analysis Report for %s ---\n", filename);
    printf("Total Characters : %d\n", characters);
    printf("Total Words      : %d\n", words);
    printf("Total Lines      : %d\n", lines);
}