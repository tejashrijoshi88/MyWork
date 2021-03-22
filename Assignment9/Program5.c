// Write a program which accept accept range from user and display all numbers in between that range in reverse order.
// input = int
// output = int
// time complexity O(n)

#include <stdio.h>

void RangeDisplayRev(int iStart,int iEnd)
{
    if(iStart >iEnd)
    {
        printf("Invalid Range");
    }
    for(int i = iEnd;i>=iStart;i--)
    {
        printf("%d ",i);
    }
}

int main()
{
    int iValue1=0;
    int iValue2=0;

    printf("Enter first number ");
    scanf("%d",&iValue1);
    printf("Enter second number ");
    scanf("%d",&iValue2);
    RangeDisplayRev(iValue1,iValue2);
    return 0;
}


