// Accept a number from user and return count of digits between 3 and 6 
// integer = integer
// output = integer
// Time Complexity O(n)
#include <stdio.h>
int CountRange(int iNo)
{
    int iDigit=0;
    int iCnt=0;
    if(iNo<=0)
    {
        iNo=-iNo;
    }
    while(iNo>0)
    {
        iDigit=iNo%10;
        if(iDigit>3 && iDigit <7)
        {
            iCnt++;
        }
        iNo=iNo/10;
    }
    return iCnt;
}
int main()
{
    int iVal=0;
    int iRet=0;
    printf("Enter number ");
    scanf("%d",&iVal);

    iRet=CountRange(iVal);
    printf("%d",iRet);
    return 0;
}