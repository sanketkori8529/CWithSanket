#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50

struct Student {
    int rollNo;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade[10];
};

const char *subjects[5] = {
    "Mathematics",
    "Science",
    "English",
    "Social Studies",
    "Computer Science"
};

void assignGrade(float percentage, char *grade) {
    if (percentage >= 90)
        strcpy(grade, "A+");
    else if (percentage >= 80)
        strcpy(grade, "A");
    else if (percentage >= 70)
        strcpy(grade, "B");
    else if (percentage >= 60)
        strcpy(grade, "C");
    else if (percentage >= 50)
        strcpy(grade, "D");
    else
        strcpy(grade, "F (Fail)");
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nMaximum student limit reached!\n");
        return;
    }

    struct Student s;
    s.total = 0;

    printf("\n--- ADD NEW STUDENT RECORD ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);
    getchar(); // Clear newline buffer

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("Enter marks for %s (0-100): ", subjects[i]);
            scanf("%f", &s.marks[i]);
            if (s.marks[i] >= 0 && s.marks[i] <= 100) {
                s.total += s.marks[i];
                break;
            } else {
                printf("Invalid marks! Enter a value between 0 and 100.\n");
            }
        }
    }

    s.percentage = s.total / 5.0;
    assignGrade(s.percentage, s.grade);

    students[*count] = s;
    (*count)++;
    printf("\nReport card generated for %s!\n", s.name);
}

void printSingleReport(struct Student s) {
    printf("\n============================================\n");
    printf("            STUDENT REPORT CARD             \n");
    printf("============================================\n");
    printf("Roll No   : %d\n", s.rollNo);
    printf("Name      : %s\n", s.name);
    printf("--------------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-20s: %6.2f / 100\n", subjects[i], s.marks[i]);
    }
    printf("--------------------------------------------\n");
    printf("Total Marks         : %.2f / 500\n", s.total);
    printf("Percentage          : %.2f%%\n", s.percentage);
    printf("Grade               : %s\n", s.grade);
    printf("============================================\n");
}

void displayAllReports(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printSingleReport(students[i]);
    }
}

void searchStudent(struct Student students[], int count) {
    int rollNo, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printSingleReport(students[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student record not found.\n");
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0, choice;

    while (1) {
        printf("\n=== STUDENT REPORT CARD SYSTEM ===\n");
        printf("1. Add Student Marks & Generate Report\n");
        printf("2. Display All Report Cards\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayAllReports(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("\nExiting Report Card System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select 1-4.\n");
        }
    }

    return 0;
}