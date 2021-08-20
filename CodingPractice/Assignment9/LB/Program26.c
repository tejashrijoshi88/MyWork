// Accept number from user and return its reverse number
// input = 7500
// output = 57
// input = 4512
// output = 2154


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - Reverse
// input - integer
// output - integer
// Desc - It is used to show reverse of given number
// Date - 08/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>

int Reverse(int iNo)
{
    int iReverse=0;
    int iDigit=0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    while(iNo>0)
    {
        iDigit = iNo%10;
        iReverse = (iReverse*10)+iDigit;
        iNo=iNo/10;
    }
    return iReverse;
}
int main()
{
    int iVal1=0;
    int iRet=0;
    printf("Enter Number ");
    scanf("%d",&iVal1);
    iRet=Reverse(iVal1);
    printf("Reverse of number %d is %d",iVal1,iRet);
    return 0;
}