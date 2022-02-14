// Accept a number from user and print summation of non factors of the number
// input = int
// output = int

#include <stdio.h>
int SumNonFact(int iNo)
{
    int i=0;
    int iSum=0;
    if(iNo<=0)
    {
        iNo=-iNo;
    }
    for(i=1;i<iNo;i++)
    {
        if(iNo%i!=0)
        {
            iSum = iSum+i;
        }
    }
    return iSum;
}
int main()
{
    int iVal=0;
    int iRet=0;
    printf("Enter number ");
    scanf("%d",&iVal);

    iRet=SumNonFact(iVal);
    printf("Output %d",iRet);
    return 0;
}