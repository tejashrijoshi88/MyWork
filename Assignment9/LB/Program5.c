// take a number from user and display addition of all numbers till that number
// input = 4
// output = 1+2+3+4=10
// consider only positive number

/*
start
end

*/
#include <stdio.h>
int Sum(int iValue)
{
    int sum=0;
    if(iValue==0)
    {
        return 0;
    }
    if(iValue <0)
    {
        iValue = -iValue;
    }
    for (int i=1;i<=iValue;i++)
    {
        sum=sum+i;
    }
    
    return sum;
    
}
int main()
{
    int iNo=0;
    int iRet=0;
    printf("Take the input number\n");
    scanf("%d",&iNo);
    iRet=Sum(iNo);
    printf("Addition is %d",iRet);
    return 0;
}