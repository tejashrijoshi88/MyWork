// Accept two numbers from user and calculate its power
// input = 2 4
// output = 2 * 2* 2 * 2* = 16


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - Power
// input - integer,integer
// output - power
// Desc - It is used to calculate the second number power for first number
// Date - 03/02/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
int Power(int iNo1,int iNo2)
{
    int iPower=1;
    if (iNo1<0)
    {
        iNo1=-iNo1;
    }
    if (iNo2<0)
    {
        iNo2=-iNo2;
    }
    for (int i =1 ; i <= iNo2 ; i++)
    {
        iPower = iPower * iNo1;
    }
    return iPower;
}
int main()
{
    int iValue1=0,iValue2=0;
    int iRet=0;

    printf("Enter first number\n");
    scanf("%d",&iValue1);

    printf("Enter second number\n");
    scanf("%d",&iValue2);

    iRet = Power(iValue1,iValue2);
    printf("The %d th power of %d is %d",iValue2,iValue1,iRet);
}