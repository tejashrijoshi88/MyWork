// Accept a number from user and return count of odd digits
// input = int
// output =  int
// time complexity O(n)
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

int CountOdd(int iNo)
{
    int iDigit=0;
    int iCnt=0;
    if(iNo <0)
    {
        iNo=-iNo;
    }
    while(iNo>0)
    {
        iDigit = iNo%10;
        if(iDigit%2!=0)
        {
            iCnt++;;
        }
        iNo=iNo/10;
    }
    return iCnt;
}
int main()
{
    int iVal;
    int iRet=false;
    printf("Enter Number ");
    scanf("%d",&iVal);
    iRet=CountOdd(iVal);
    printf("%d",iRet);
    return 0;
}