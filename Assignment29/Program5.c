//Write a program which accept one number from user and toggle contents
//of first and last nibble of the number. Return modified number. (Nibble is a
//group of four bits)

#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

UINT ToggleBit(UINT iValue)
{
    UINT iMask= 0xF000000F;
    UINT iResult=0;
    iResult=iValue^iMask;
    return iResult;
}
int main()
{
    UINT iNo=0;
    UINT iRet=0;
    printf("Enter Number ");
    scanf("%u",&iNo);
    iRet=ToggleBit(iNo);
    printf("%u",iRet);
    return 0;
}
