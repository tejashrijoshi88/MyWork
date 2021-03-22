// Accept number from user and display that number of stars
// input = 3 3 
// output - * * *
        //  * * *
        //  * * *


/////////////////////////////////////////////////////////////////////
// Function Name - Display
// input - integer
// output - Pattern
// Desc - Displays specific given pattern
// Date - 10/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
void Display(unsigned int iRow,unsigned int iCol)
{
    for(int i=1;i<=iRow;i++)
    {
        for(int j=1;j<=iCol;j++)
        {
            printf("*\t");
        }
        printf("\n");
    }
}
int main()
{
    unsigned int iVal1=0;
    unsigned int iVal2=0;
    printf("Enter Number of rows ");
    scanf("%u",&iVal1);
    printf("Enter Number of cols ");
    scanf("%u",&iVal2);

    Display(iVal1,iVal2);
    return 0;
}