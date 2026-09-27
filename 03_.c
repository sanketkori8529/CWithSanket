/*C program to calculate the area of a rectangle
Method 2 - Using inputs supplied by the user */
#include <stdio.h>
int main()
{
   int Length, Breadth;
   printf("Enter the Length : ");
   scanf("%d",&Length);

   printf("Enter the Breadth : ");
   scanf("%d",&Breadth);

   printf("Area of Rectangle = %d",Length*Breadth);

    return 0;
}