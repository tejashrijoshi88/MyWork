// Accept number from user and return diff between min and max
// input = 57
// output = 2
// input = 121
// output - 1


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - DiffMinMAx
// input - integer
// output - integer
// Desc - returns min digit
// Date - 09/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
/*

*/
#include <stdio.h>
#include <stdbool.h>
typedef unsigned long int UNSIGN;
int DiffMinMax(UNSIGN iNo)
{
    int iMin=9;
    int iMax=0;
    int iDigit=0;
    
    if(iNo<0)
    {
        iNo=-iNo;
    }
    while(iNo>0)
    {
        iDigit = iNo%10;
        if(iDigit <iMin )
        {
            iMin=iDigit;
        }
        if(iDigit>iMax)
        {
            iMax=iDigit;
        }
        iNo=iNo/10;
    }
    return (iMax-iMin);
    
}
int main()
{
    UNSIGN iVal1=0;
    int iRet=0;
    printf("Enter Number ");
    scanf("%d",&iVal1);
    iRet=DiffMinMax(iVal1);
    printf("%d",iRet);
    return 0;
}