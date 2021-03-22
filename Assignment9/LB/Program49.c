// Accept number from user and display that number of stars
// input = 5
// output - A B C D E
// input = 3
// output A B C


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
    char ch='A';
    printf("\n");
    for(int i=1;i<=iNo;i++)
    {
        printf("%c\t",ch);
        ch++;
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