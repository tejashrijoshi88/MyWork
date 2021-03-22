// Accept number from user and return largest digit
// input = 57
// output = 7
// input = 121
// output - 2


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - MaxDigit
// input - integer
// output - integer
// Desc - returns lagest digit
// Date - 08/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
/*

*/
#include <stdio.h>
#include <stdbool.h>
int MaxDigit(int iNo)
{
    int iMax=0;
    int iDigit=0;
    
    if(iNo<0)
    {
        iNo=-iNo;
    }
    while(iNo>0)
    {
        iDigit = iNo%10;
        if(iDigit > iMax)
        {
            iMax=iDigit;
            if(iMax==9)
            {
                break;
            }
        }

        iNo=iNo/10;
    }
    return iMax;
    
}
int main()
{
    int iVal1=0;
    int iRet=0;
    printf("Enter Number ");
    scanf("%d",&iVal1);
    iRet=MaxDigit(iVal1);
    printf("%d",iRet);
    return 0;
}