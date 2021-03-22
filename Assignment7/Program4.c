// Accept a number from user and return multiplication of all digits
// integer = integer
// output = integer
// Time Complexity O(n)
#include <stdio.h>
int MultDigits(int iNo)
{
    int iDigit=0;
    int iMul=1;
    if(iNo<=0)
    {
        iNo=-iNo;
    }
    while(iNo>0)
    {
        iDigit=iNo%10;
        if(iDigit!=0)
        {
            iMul= iMul*iDigit;
        }
        iNo=iNo/10;
    }
    return iMul;
}
int main()
{
    int iVal=0;
    int iRet=0;
    printf("Enter number ");
    scanf("%d",&iVal);

    iRet=MultDigits(iVal);
    printf("%d",iRet);
    return 0;
}