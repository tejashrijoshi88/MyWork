//Write a program which checks whether first and last bit is On or
//OFF. First bit means bit number 1 and last bit means bit number 32.
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

BOOL ChkBit(unsigned int iValue)
{
    unsigned int iMask= 0x80000001;
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
        printf("Bit is ON");
    }
    else
    {
        printf("Bit is Off");
    }
    return 0;
}
