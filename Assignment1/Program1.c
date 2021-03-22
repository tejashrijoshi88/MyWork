// Program to divide two numbers
// input = int,int
// output = int

#include <stdio.h>
int Divide(int iNo1, int iNo2)
{
    int iAns=0;
    if(iNo2==0)
    {
        return -1;
    }
    iAns = iNo1/iNo2;
    return iAns;
}
int main()
{
    int iVal1=15;
    int iVal2=5;
    int iRet=0;
    /*printf("Provide first input number\n");
    scanf("%d",&iVal1);

    printf("Provide second input number\n");
    scanf("%d",&iVal2);
    */
    iRet=Divide(iVal1,iVal2);
    printf("Division is %d",iRet);
    return 0;
}