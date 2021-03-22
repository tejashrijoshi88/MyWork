// Write a program which accept range from user and return addition of all numbers
// in between that range. (Range should contains positive numbers only)
//Input : 23 30
//Output : 212
//Input : 10 18
//Output : 126
// Time Complexity O(n)
#include <stdio.h>
int RangeSum(int iNo1,int iNo2)
{
    int iSum=0;
    if(iNo2<0 || iNo1<0)
    {
        return -1;
    }
    if(iNo1>iNo2)
    {
        return -1;
    }
    for(int i = iNo1;i<=iNo2;i++)
    {
        iSum=iSum+i;
    }return iSum;
}
int main()
{
    int iVal1=0;
    int iVal2=0;
    int iRet=0;
    printf("Enter first number ");
    scanf("%d",&iVal1);
    printf("Enter second number ");
    scanf("%d",&iVal2);
    iRet=RangeSum(iVal1,iVal2);
    if(iRet==-1)
    {
        printf("Invalid Range");
    }
    else
    {
        printf("%d",iRet);
    }
    return 0;
}