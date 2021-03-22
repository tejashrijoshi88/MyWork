// Accept number from user and display digits
// input = 12
// output = 3
// input = 1345
// output = 13


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - Display
// input - integer
// output - digits
// Desc - It is used to show digits of number
// Date - 03/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>

void Display(int iNo)
{
    int iDigit=0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    while(iNo >0)
    {
        iDigit = iNo%10;
        printf("%d\n",iDigit);
        iNo=iNo/10;
    }
    
}
int main()
{
    int iVal=0;
    int iRet=0;
    printf("Enter Number ");
    scanf("%d",&iVal);
    Display(iVal);
    
    return 0;
}