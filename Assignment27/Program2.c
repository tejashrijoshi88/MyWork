//Write a program which checks whether 5th and 18th bit is On or OFF.
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

BOOL ChkBit(unsigned int iValue)
{
    unsigned int iMask= 0x00020010;
    unsigned int iResult=0;
    iResult=iValue&iMask;
    if(iResult==iMask)
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
    unsigned int iNo=0;
    BOOL bRet=false;
    printf("Enter Number ");
    scanf("%u",&iNo);
    bRet=ChkBit(iNo);
    if(bRet==true)
    {
        printf("Bit os ON");
    }
    else
    {
        printf("Bit os Off");
    }
    return 0;
}
