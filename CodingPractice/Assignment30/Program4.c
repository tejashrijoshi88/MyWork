//Write a program which accept one number , two positions from user and
//check whether bit at first or bit at second position is ON or OFF.
//Input : 10 3 7
//Output : TRUE
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

BOOL ChkBit(UINT iValue, int iPos1, int iPos2)
{
    if((iPos1<1 || iPos1>32) || (iPos2<1 || iPos2>32))
    {
        return false;
    }
    UINT iMask1 = (0x00000001)<<(iPos1-1);
    UINT iMask2 = (0x00000001)<<(iPos2-1);
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
    int iPos1=0;
    int iPos2=0;
    BOOL bRet=false;
    printf("Enter Number ");
    scanf("%u",&iNo);
    printf("Enter pos1 ");
    scanf("%u",&iPos1);
    printf("Enter pos2 ");
    scanf("%u",&iPos2);
    bRet=ChkBit(iNo,iPos1,iPos2);
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
