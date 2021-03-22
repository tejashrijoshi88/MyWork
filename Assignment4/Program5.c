// Accept number from user and return difference between summation of factors and not factors
// input = int
// output = int

#include <stdio.h>

int FactDiff(int iNo)
{
    int factSum=0;
    int nonFactSum=0;
    for(int i=1;i<iNo;i++)
    {
        if(iNo%i==0)
        {
            factSum = factSum+i;
        }
        else
        {
            nonFactSum = nonFactSum+i;
        }
    }
    return (factSum-nonFactSum);
}

int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter number ");
    scanf("%d",&iValue);

    iRet =FactDiff(iValue);

    printf("%d",iRet);
    return 0;
}


