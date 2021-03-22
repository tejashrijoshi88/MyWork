// Accept number from user and display that number of stars
// input = 5
// output - 5 * 4 * 3 * 2 * 1 *


/////////////////////////////////////////////////////////////////////
// Function Name - Display
// input - integer
// output - Pattern
// Desc - Displays specific given pattern
// Date - 10/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
void Display(unsigned int iNo)
{
    printf("\n");
    for(int i=iNo;i>=1;i--)
    {
        printf("*\t%d\t",i);
    }
    printf("\n");
}
int main()
{
    unsigned int iVal=0;
    printf("Enter Number ");
    scanf("%u",&iVal);
    Display(iVal);
    return 0;
}