#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.txt"

struct Contact {
    char name[50];
    char phone[15];
};

void addContact();
void viewContacts();
void searchContact();
void deleteContact();

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf("          C CONTACT BOOK            \n");
        printf("====================================\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option! Choose between 1 and 5.\n");
        }
    }
    return 0;
}

void addContact() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Contact c;
    printf("\nEnter Name (no spaces, e.g. Rohan_Verma): ");
    scanf("%49s", c.name);
    printf("Enter Phone Number: ");
    scanf("%14s", c.phone);

    fprintf(fp, "%s %s\n", c.name, c.phone);
    fclose(fp);
    printf("Contact saved successfully!\n");
}

void viewContacts() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo contacts found yet.\n");
        return;
    }

    struct Contact c;
    int count = 0;
    printf("\n--- ALL CONTACTS ---\n");
    while (fscanf(fp, "%49s %14s", c.name, c.phone) != EOF) {
        printf("%-20s : %s\n", c.name, c.phone);
        count++;
    }

    if (count == 0) {
        printf("Contact book is empty.\n");
    }
    fclose(fp);
}

void searchContact() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo contacts found yet.\n");
        return;
    }

    char target[50];
    struct Contact c;
    int found = 0;

    printf("\nEnter Name to search: ");
    scanf("%49s", target);

    while (fscanf(fp, "%49s %14s", c.name, c.phone) != EOF) {
        if (strcasecmp(c.name, target) == 0) {
            printf("Found -> %s : %s\n", c.name, c.phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Contact '%s' not found.\n", target);
    }
    fclose(fp);
}

void deleteContact() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo contacts found yet.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    char target[50];
    struct Contact c;
    int found = 0;

    printf("\nEnter exact Name to delete: ");
    scanf("%49s", target);

    while (fscanf(fp, "%49s %14s", c.name, c.phone) != EOF) {
        if (strcasecmp(c.name, target) == 0) {
            found = 1; // Skip writing this record to temp file
        } else {
            fprintf(temp, "%s %s\n", c.name, c.phone);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Contact '%s' deleted successfully!\n", target);
    } else {
        printf("Contact '%s' not found.\n", target);
    }
}