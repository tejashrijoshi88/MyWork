// Accept a number from user and check weather it contains 0 or not
// input = int
// output =  bool
// time complexity O(n)
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

bool ChkZero(int iNo)
{
    int iDigit=0;
    if(iNo <0)
    {
        iNo=-iNo;
    }
    while(iNo>0)
    {
        iDigit = iNo%10;
        if(iDigit==0)
        {
            break;
        }
        iNo=iNo/10;
    }
    if(iNo==0)
    {
        return false;
    }
    else
    {return true;}
}
int main()
{
    int iVal;
    bool bRet=false;
    printf("Enter Number ");
    scanf("%d",&iVal);
    bRet=ChkZero(iVal);
    if(bRet==true)
    {
        printf("It contains Zero");
    }
    else
    {
        printf("Does not contain Zero");
    }
    return 0;
}