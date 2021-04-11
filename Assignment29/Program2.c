//Write a program which accept one number and position from user and off
//that bit. Return modified number.
//Input : 10 2
//Output : 8
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

UINT OffBit(UINT iValue,int iPos)
{
    if((iPos<1) || (iPos>32))
    {
        return false;
    }
    UINT iMask= 0xFFFFFFFE<<(iPos-1);
    UINT iResult=0;
    iResult=iValue&iMask;
    return iResult;
}
int main()
{
    UINT iNo=0;
    UINT iRet=false;
    int iPos=0;
    printf("Enter Number ");
    scanf("%u",&iNo);
    printf("Enter Pos ");
    scanf("%d",&iPos);
    iRet=OffBit(iNo,iPos);
    printf("%u",iRet);
    return 0;
}
