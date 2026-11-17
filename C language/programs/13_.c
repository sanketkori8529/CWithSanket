//Concept of And    Or

# include<stdio.h>
int  main()
{
    int a , b;

    if(a = 1,b=0)
    {
        printf("1 the value of a and b is %d\n",a&&b);
        printf("1 the value of a or b is %d\n",a||b);
    }
    if(a = 0,b=1)
    {
        printf("2 the value of a and b is %d\n",a&&b);
        printf("2 the value of a or b is %d\n",a||b);
    }
    if(a = 1,b=1)
    {
        printf("3 the value of a and b is %d\n",a&&b);
        printf("3 the value of a or b is %d\n",a||b);
    }
    if(a = 0,b=0)
    {
        printf("4 the value of a and b is %d\n",a&&b);
        printf("4 the value of a or b is %d\n",a||b);
    }
    return 0;
}