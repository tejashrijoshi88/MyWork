//Write a program which accept one number from user and count number of
//ON (1) bits in it without using % and / operator.
//Input : 11
//Output : 3
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

UINT CountOne(UINT iValue)
{
    UINT iMask= 0x00000001;
    UINT iResult=0;
    int iCount=0;
    for(int i=1;i<32;i++)
    {
        iResult=iValue&iMask;
        if(iResult==iMask)
        {
            iCount++;
        }
        iMask=iMask<<1;
    }
    return iCount;
}
int main()
{
    UINT iNo=0;
    UINT iRet=0;
    printf("Enter Number ");
    scanf("%u",&iNo);
    iRet=CountOne(iNo);
    printf("%u",iRet);
    return 0;
}
