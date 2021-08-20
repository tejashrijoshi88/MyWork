// Accept number from user and return count of even digits
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

int EvenDigits(int iNo)
{
    int iCount=0;
    int iDigit=0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    if(iNo==0)
    {
        return 1;
    }
    while(iNo>0)
    {
        iDigit = iNo%10;
        if(iDigit %2 ==0)
        {
            iCount++;
        }
        iNo=iNo/10;
    }
    return iCount;
}
int main()
{
    int iVal=0;
    int iRet=0;
    printf("Enter Number ");
    scanf("%d",&iVal);
    iRet=EvenDigits(iVal);
    printf("Count of even digits is %d ",iRet);
    return 0;
}