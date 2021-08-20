// Accept number from user and check weather number is even or odd
// input = 4
// output = Its even
// input = 7 
// output = Its odd

/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - ChkEven
// input - integer
// output - boolean
// Desc - It is used to check weather it is even or odd
// Date - 03/01/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
bool ChkEven(int iNo)
{
    if(iNo %2 == 0)
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
    bRet=ChkEven(iValue);
    if(bRet==true)
    {
        printf("%d is even number\n",iValue);
    }
    else
    {
        printf("%d is odd number\n",iValue);
    }
    return 0;
}
