// Accept two numbers from user and check weather first number is divisible by second number or not
// input = first no: 15 second No : 5
// output = Yes
// input = first no: 15 second No : 7
// output = No

/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - ChkDivisible
// input - integer,integer
// output - boolean
// Desc - It is used to check weather first number is divisible by second number
// Date - 03/01/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
bool ChkDivisible(int iNo1,int iNo2)
{
    if((iNo1%iNo2)==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
int main()
{
    int iValue1= 0;
    int iValue2=0;
    bool bRet= false;
    printf("Enter First Number");
    scanf("%d",&iValue1);
    printf("Enter second Number");
    scanf("%d",&iValue2);
    bRet=ChkDivisible(iValue1,iValue2);
    if(bRet==true)
    {
        printf("%d is divisible by %d",iValue1,iValue2);
    }
    else
    {
        printf("%d is not divisible by %d",iValue1,iValue2);
    }
    return 0;
}
