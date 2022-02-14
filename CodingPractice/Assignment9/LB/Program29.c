// Accept number from user and return Min digit
// input = 57
// output = 5
// input = 121
// output - 1


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - MinDigit
// input - integer
// output - integer
// Desc - returns min digit
// Date - 08/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
/*

*/
#include <stdio.h>
#include <stdbool.h>
int MinDigit(int iNo)
{
    int iMin=9;
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
        if(iMin==0)
        {
            break;
        }
        iNo=iNo/10;
    }
    return iMin;
    
}
int main()
{
    int iVal1=0;
    int iRet=0;
    printf("Enter Number ");
    scanf("%d",&iVal1);
    iRet=MinDigit(iVal1);
    printf("%d",iRet);
    return 0;
}