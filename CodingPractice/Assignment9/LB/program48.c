// Accept number from user and display that number of stars
// input = 5 A
// output - A A A A A
// input = 3 C
// output C C C


/////////////////////////////////////////////////////////////////////
// Function Name - Display
// input - integer
// output - Pattern
// Desc - Displays specific given pattern
// Date - 10/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
void Display(unsigned int iNo,char cVal)
{
    printf("\n");
    for(int i=1;i<=iNo;i++)
    {
        printf("%c\t",cVal);
    }
    printf("\n");
}
int main()
{
    unsigned int iVal=0;
    char cValue='\0';
    printf("Enter Number ");
    scanf("%u",&iVal);
    printf("Enter Character ");
    scanf(" %c",&cValue);
    Display(iVal,cValue);
    return 0;
}