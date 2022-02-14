//Write a program which accept two numbers from user and display position
//of common ON bits from that two numbers.
//Input : 10 15 (1010 1111)
//Output : 2 4
#include <stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

#define true 1
#define false 0

void CommonBits(UINT iValue1,UINT iValue2)
{
    UINT iMask= 0x00000001;
    UINT iResult1=0;
    UINT iResult2=0;
    for(int i=1;i<32;i++)
    {
        iResult1=iValue1&iMask; 
        iResult2=iValue1&iMask;   
        if(iResult1==iMask && iResult2==iMask)
        {
            printf("%d ",i);
        }
        iMask=iMask<<1;
    }
}
int main()
{
    UINT iNo1=0;
    UINT iNo2=0;
    UINT iRet=0;
    printf("Enter Number one");
    scanf("%u",&iNo1);
    printf("Enter Number two");
    scanf("%u",&iNo2);
    CommonBits(iNo1,iNo2);

    return 0;
}
