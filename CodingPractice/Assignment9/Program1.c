// 1.Write a program which accept range from user and display all numbers in between that range.
/* Input : 23 35
Output : 23 24 25 26 27 28 29 30 31 32 33 34 35
Input : 10 18
Output : 10 11 12 13 14 15 16 17 18
Input : 10 10
Output : 10
Input : -10 2
Output : -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2
Input : 90 18
Output : Invalid range
*/
// time complexity O(n) where n = difference between two numbers
#include <stdio.h>
void RangeDisplay(int iNo1,int iNo2)
{
    if(iNo1>iNo2)
    {
        printf("Invalid Range");
    }
    for(int i = iNo1;i<=iNo2;i++)
    {
        printf("%d ",i);
    }
}
int main()
{
    int iVal1=0;
    int iVal2=0;
    printf("Enter the first Number ");
    scanf("%d",&iVal1);
    printf("Enter the second Number ");
    scanf("%d",&iVal2);
    RangeDisplay(iVal1,iVal2);
    return 0;
}
