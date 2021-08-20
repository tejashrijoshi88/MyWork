// Accept number from user and return addition of all digits
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
// output - integer
// Desc - It is used to show addition of digits
// Date - 03/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>

int SumDigits(int iNo)
{
    int iSum=0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    while(iNo >0)
    {
        iSum= iSum+(iNo%10);
        iNo=iNo/10;
    }
    return iSum;
}
int main()
{
    int iVal=0;
    int iRet=0;
    printf("Enter Number ");
    scanf("%d",&iVal);
    iRet=SumDigits(iVal);
    printf("Sum is %d ",iRet);
    return 0;
}