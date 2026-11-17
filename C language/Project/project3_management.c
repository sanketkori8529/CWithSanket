#include <stdio.h>
#include <stdlib.h>

// Structure for Student Record
struct Student {
    int roll;
    char name[30];
    float marks;
};

// Structure for Library Book Record
struct Book {
    int id;
    char title[30];
    char author[30];
};

// Function Declarations
void addStudent();
void viewStudents();
void searchStudent();
void addBook();
void viewBooks();
void calculateFine();

int main() {
    int ch;

    do {
        printf("\n================================================\n");
        printf("   STUDENT & LIBRARY MANAGEMENT SYSTEM (FILE)   \n");
        printf("================================================\n");
        printf("1. Add New Student Record\n");
        printf("2. View All Student Records\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Add New Book to Library\n");
        printf("5. View All Library Books\n");
        printf("6. Calculate Library Late Fine\n");
        printf("0. Exit\n");
        printf("------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                addBook();
                break;
            case 5:
                viewBooks();
                break;
            case 6:
                calculateFine();
                break;
            case 0:
                printf("Exiting System. All records are saved in files!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 0);

    return 0;
}

// 1. Add Student Record using "a" (Append Mode)
void addStudent() {
    struct Student s;
    FILE *fp;

    // "a" mode opens the file to add data at the end without deleting old data
    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Add Student Details ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter First Name (use _ for space): ");
    scanf("%s", s.name);
    printf("Enter Marks (out of 100): ");
    scanf("%f", &s.marks);

    // Write data into the file
    fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    fclose(fp);

    printf("Student record saved successfully in students.txt!\n");
}

// 2. View All Students using "r" (Read Mode) and EOF
void viewStudents() {
    struct Student s;
    FILE *fp;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("\nNo student records found! Please add a student first.\n");
        return;
    }

    printf("\n--- List of All Students ---\n");
    printf("Roll No\t\tName\t\tMarks\n");
    printf("----------------------------------------\n");

    // Read file line by line until End Of File (EOF)
    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        printf("%d\t\t%s\t\t%.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

// 3. Search Student by Roll No using flag variable
void searchStudent() {
    struct Student s;
    FILE *fp;
    int searchRoll, flag = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("\nNo student file found!\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        if (s.roll == searchRoll) {
            printf("\nRecord Found!\n");
            printf("Roll No: %d\nName   : %s\nMarks  : %.2f\n", s.roll, s.name, s.marks);
            if (s.marks >= 33.0) {
                printf("Status : PASS\n");
            } else {
                printf("Status : FAIL\n");
            }
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Sorry, no student found with Roll Number %d.\n", searchRoll);
    }

    fclose(fp);
}

// 4. Add Book to Library File
void addBook() {
    struct Book b;
    FILE *fp;

    fp = fopen("library.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Add New Library Book ---\n");
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Book Title (use _ for space): ");
    scanf("%s", b.title);
    printf("Enter Author Name (use _ for space): ");
    scanf("%s", b.author);

    fprintf(fp, "%d %s %s\n", b.id, b.title, b.author);
    fclose(fp);

    printf("Book added successfully to library.txt!\n");
}

// 5. View All Books from Library File
void viewBooks() {
    struct Book b;
    FILE *fp;

    fp = fopen("library.txt", "r");
    if (fp == NULL) {
        printf("\nLibrary is empty! Add some books first.\n");
        return;
    }

    printf("\n--- Library Book Inventory ---\n");
    printf("Book ID\t\tTitle\t\tAuthor\n");
    printf("----------------------------------------\n");

    while (fscanf(fp, "%d %s %s", &b.id, b.title, b.author) != EOF) {
        printf("%d\t\t%s\t\t%s\n", b.id, b.title, b.author);
    }

    fclose(fp);
}

// 6. Simple Library Late Fine Calculator
void calculateFine() {
    int daysLate, fine = 0;

    printf("\n--- Library Late Fine Calculator ---\n");
    printf("Enter number of days after due date: ");
    scanf("%d", &daysLate);

    if (daysLate <= 0) {
        printf("Returned on time! Fine = Rs. 0\n");
    } else if (daysLate <= 5) {
        fine = daysLate * 2; // Rs. 2 per day for first 5 days
        printf("Late Fine = Rs. %d (Rs. 2/day)\n", fine);
    } else if (daysLate <= 10) {
        fine = (5 * 2) + ((daysLate - 5) * 5); // Rs. 5 per day after 5 days
        printf("Late Fine = Rs. %d\n", fine);
    } else {
        fine = (5 * 2) + (5 * 5) + ((daysLate - 10) * 10); // Rs. 10 per day after 10 days
        printf("Late Fine = Rs. %d (Warning: Membership may be cancelled!)\n", fine);
    }
}