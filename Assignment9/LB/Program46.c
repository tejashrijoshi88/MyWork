// Accept number from user and display that number of stars
// input = 5
// output - 1 * 2 * 3 * 4 * 5 *


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
    for(int i=1;i<=iNo;i++)
    {
        printf("%d\t*\t",i);
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