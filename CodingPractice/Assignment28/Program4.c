//Write a program which accept one number from user and toggle 7th and 10th bit of that
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
    UINT iMask= 0x00000240;
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
