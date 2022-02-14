// Accept number from user and check weather number is even or odd
// input = int
// output = stars for given number

#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
bool ChkEven(int iNum)
{
    if(iNum%2==0)
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
    int iVal=0;
    bool bRet=false;
    printf("Enter number");
    scanf("%d",&iVal);
    
    bRet = ChkEven(iVal);
    if(bRet == true)
    {
        printf("Number is even");
    }
    else
    {
        printf("Number is odd");
    }
    return 0;
}