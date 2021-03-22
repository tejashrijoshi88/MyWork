// Accept number from user and return difference btween summation of even digits and summation of odd digits
// input = int
// output = int
// time complexity O(n)

#include <stdio.h>

int CountDiff(int iNo)
{
    int iDigit=0;
    int iEvenSum=0;
    int iOddSum=0;
    while(iNo>0)
    {
        iDigit=iNo%10;
        if(iDigit%2==0)
        {
            iEvenSum=iEvenSum+iDigit;
        }
        else
        {
            iOddSum=iOddSum+iDigit;
        }
        iNo=iNo/10;
    }
    return (iEvenSum-iOddSum);
}

int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter number ");
    scanf("%d",&iValue);

    iRet =CountDiff(iValue);

    printf("%d",iRet);
    return 0;
}


