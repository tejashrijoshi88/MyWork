//Write a program which accept one number and position from user and
//check whether bit at that position is on or off. If bit is one return TURE
//otherwise return FALSE.
//Input : 10 2
//Output : TRUE
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

BOOL ChkBit(UINT iValue,int iPos)
{
    if((iPos<1) || (iPos>32))
    {
        return false;
    }
    UINT iMask= 0x00000001<<(iPos-1);
    UINT iResult=0;
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
    UINT iNo=0;
    BOOL bRet=false;
    int iPos=0;
    printf("Enter Number ");
    scanf("%u",&iNo);
    printf("Enter Pos ");
    scanf("%d",&iPos);
    bRet=ChkBit(iNo,iPos);
    if(bRet==true)
    {
        printf("bit is ON");
    }
    else
    {
        printf("bit is Off");
    }
    return 0;
}
