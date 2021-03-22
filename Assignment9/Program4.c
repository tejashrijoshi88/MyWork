// Write a program which accept range from user and return addition of all even
// numbers in between that range. (Range should contains positive numbers only)
//Input : 23 30
//Output : 108
//Input : 10 18
//Output : 70
//Input : -10 2
//Output : Invalid range
//Input : 90 18
//Output : Invalid range
// Time Complexity O(n/2) where n is difference between two numbers
#include <stdio.h>
int RangeSumEven(int iNo1,int iNo2)
{
    int i=0;
    int iSum=0;
    if(iNo1 <0 || iNo2 <0)
    {
        return -1;
    }
    if(iNo1>iNo2)
    {
        return -1;
    }
    if(iNo1%2==0)
    {
        i=iNo1;
    }
    else
    {
        i=iNo1+1;
    }
    for(;i<=iNo2;i=i+2)
    {
        iSum=iSum+i;
    }
    return iSum;
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
    iRet=RangeSumEven(iVal1,iVal2);
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