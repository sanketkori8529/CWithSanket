// C program to calculate calculate the volume of a cylinder given its radius and height

# include <stdio.h>
int main()
{
   float Radius , Height,Area;
   float pie = 3.14;
   printf("Enter the Radius : ");
   scanf("%f",&Radius);

   printf("Enter the Height : ");
   scanf("%f",&Height);

   Area = pie * Radius*Radius*Height;

   printf("Area of Cylinder = %.2f",Area);
   return 0;
}