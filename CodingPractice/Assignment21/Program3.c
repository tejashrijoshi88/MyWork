//Accept Character from user and check whether it is digit or not
//(0-9).
//Input : 7
//Output : TRUE
//Input : d
//Output : FALSE
#include <stdio.h>
#define true 1
#define false 0
typedef int bool;

bool ChkDigit(char ch)
{
    if(ch >=48 && ch <=57)
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
    char cValue='\0';
    bool bRet=false;
    printf("Enter the character: ");
    scanf("%c",&cValue);
    bRet=ChkDigit(cValue);
    if(bRet==true)
    {
        printf("It is a digit");
    }
    else
    {
        printf("It is not a digit");
    }
    return 0;
}
