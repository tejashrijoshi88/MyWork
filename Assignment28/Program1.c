//Write a program which accept one number from user and off 7th bit of that
//number if it is on. Return modified number.
//Input : 79
//Output : 15
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

UINT OffBit(UINT iValue)
{
    UINT iMask= 0xFFFFFFBF;
    UINT iResult=0;
    iResult=iValue&iMask;
    return iResult;
}
int main()
{
    UINT iNo=0;
    UINT iRet=0;
    printf("Enter Number ");
    scanf("%u",&iNo);
    iRet=OffBit(iNo);
    printf("%u",iRet);
    return 0;
}
