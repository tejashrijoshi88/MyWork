// Accept number from user and display that number of stars
// input = 5
// output - * * * * *


/////////////////////////////////////////////////////////////////////
// Function Name - DiffMinMAx
// input - integer
// output - integer
// Desc - returns min digit
// Date - 10/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
void Display(unsigned int iNo)
{
    for(int i=1;i<=iNo;i++)
    {
        printf("*\t");
    }
}
int main()
{
    unsigned int iVal=0;
    printf("Enter Number ");
    scanf("%u",&iVal);
    Display(iVal);
    return 0;
}