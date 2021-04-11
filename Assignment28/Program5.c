//Write a program which accept one number from user and on its first 4 bits of that
// Return modified number.
//Input : 137
//Output : 201
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

UINT ToggleBit(UINT iValue)
{
    UINT iMask= 0x0000000F;
    UINT iResult=0;
    iResult=iValue|iMask;
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
