//Write a program which accept one number from user and range of
//positions from user. Toggle all bits from that range.
//Input : 897 9 13
//Toggle all bits from position 9 to 13 of input number ie 879.
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

UINT ToggleBitRange(UINT iValue,int iStart, int iEnd)
{
    if((iStart<1 || iStart>32) ||(iEnd<1 || iEnd >32) ||(iStart>iEnd))
    {
        return 0;
    }
    UINT iMask= 0x00000001;
    iMask <<= (iStart-1);
    for(int i=0;i<=(iEnd-iStart);i++)
    {
        iValue=iValue^iMask;
        iMask=iMask<<1;
    }   
    return iValue;
}
int main()
{
    UINT iNo=0;
    UINT iRet=0;
    int iPos1=0;
    int iPos2=0;
    printf("Enter Number ");
    scanf("%u",&iNo);
    printf("Enter pos1 ");
    scanf("%u",&iPos1);
    printf("Enter pos2 ");
    scanf("%u",&iPos2);
    iRet=ToggleBitRange(iNo,iPos1,iPos2);
    printf("%u",iRet);
    return 0;
}
