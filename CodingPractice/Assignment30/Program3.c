//Write a program which accept one number from user and check whether
//9th or 12th bit is on or off.
//Input : 257
//Output : TRUE
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

BOOL ChkBit(UINT iValue)
{
    UINT iMask1 = (0x00000001)<<8;
    UINT iMask2 = (0x00000001)<<11;
    UINT iResult1=0;
    UINT iResult2=0;
    iResult1=iValue&iMask1;
    iResult2=iValue&iMask2;
    if(iResult1==iMask1 || iResult2==iMask2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    UINT iNo=0;
    BOOL bRet=false;
    printf("Enter Number ");
    scanf("%u",&iNo);
    bRet=ChkBit(iNo);
    if(bRet==true)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}
