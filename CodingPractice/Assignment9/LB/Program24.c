// Accept number from user and number and return count of even digits frequency
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

int DigitFrequency(int iNo,int i)
{
    int iCount=0;
    int iDigit=0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    if(i <0 || i >9)
    {
        printf("Invalid Digit..");
        return 0;
    }
    while(iNo>0)
    {
        iDigit = iNo%10;
        if(iDigit==i)
        {
            iCount++;
        }
        iNo=iNo/10;
    }
    return iCount;
}
int main()
{
    int iVal1=0;
    int iVal2=0;
    int iRet=0;
    printf("Enter Number ");
    scanf("%d",&iVal1);
    printf("Enter digit ");
    scanf("%d",&iVal2);
    iRet=DigitFrequency(iVal1,iVal2);
    printf("Count of digit %d in number %d is %d",iVal2,iVal1,iRet);
    return 0;
}