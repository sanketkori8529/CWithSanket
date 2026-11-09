//Multiple Employee Details Using Structure

#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee e[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Enter employee ID, name and salary:\n");
        scanf("%d %s %f", &e[i].id, e[i].name, &e[i].salary);
    }

    printf("\nEmployee Details:\n");

    for(int i = 0; i < 5; i++)
    {
        printf("\nID = %d", e[i].id);
        printf("\nName = %s", e[i].name);
        printf("\nSalary = %.2f\n", e[i].salary);
    }

    return 0;
}