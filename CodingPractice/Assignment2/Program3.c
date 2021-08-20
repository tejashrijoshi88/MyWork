// Accept a number and write Program to print Hello if number is less than 10 otherwise Demo
// input = int
// output = Hello or Demo

#include <stdio.h>
void Display(int iNo)
{
    if(iNo < 10)
    {
        printf("Hello");
    }
    else
    {
        printf("Demo");
    }
}
int main()
{
    int iVal=0;
    printf("Enter Number");
    scanf("%d",&iVal);
    Display(iVal);
    return 0;
}