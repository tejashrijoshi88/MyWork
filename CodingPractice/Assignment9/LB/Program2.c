// accept 2 numbers from user and return min or max number
/*
Algorithm for maximum
    accept first no as no1
    accept second no as no2
    if no1 > no2
        then no1 is maximum
    otherwise 
        no2 is maximum
*/
/*
Algorithm for minimum
    accept first no as no1
    accept second no as no2
    if no1 < no2
        then no1 is minimum
    otherwise 
        no2 is minimum
*/
// includer user defined header file
#include "Header2.h"
int main()
{
    int iNo1=0;
    int iNo2=0;
    int iRet=0;
    printf("Enter first number");
    scanf("%d",&iNo1);

    printf("Enter second number");
    scanf("%d",&iNo2);
    iRet=Maximum(iNo1,iNo2);
    printf("Maximum number is : %d\n",iRet);
    return 0;
}