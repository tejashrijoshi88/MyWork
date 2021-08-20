// Accept number from user and return frequency of digits which are less than 6
// input = int
// output = int
// time complexity O(n)

#include <stdio.h>

int Count(int iNo)
{
    int iDigit=0;
    int iCnt=0;
    while(iNo>0)
    {
        iDigit=iNo%10;
        if(iDigit<6)
        {
            iCnt++;
        }
        iNo=iNo/10;
    }
    return iCnt;
}

int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter number ");
    scanf("%d",&iValue);

    iRet =Count(iValue);

    printf("%d",iRet);
    return 0;
}


