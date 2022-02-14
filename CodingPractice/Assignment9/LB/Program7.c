// Accept number from user and check weather number is divisible by 3 and 5
// input = 4
// output = No
// input = 15 
// output = Yes

/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - ChkDivisible
// input - integer
// output - boolean
// Desc - It is used to check weather number is divisible by 3 and 5
// Date - 03/01/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
bool ChkDivisible(int iNo)
{
    if(iNo%3 ==0 && iNo%5 ==0)
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
    int iValue= 0;
    bool bRet= false;
    printf("Enter Number");
    scanf("%d",&iValue);
    bRet=ChkDivisible(iValue);
    if(bRet==true)
    {
        printf("%d is divisible by 3 and 5\n",iValue);
    }
    else
    {
        printf("%d is not divisible by 3 and 5\n",iValue);
    }
    return 0;
}
