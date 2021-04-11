//Accept Character from user and check whether it is alphabet or not
//(A-Z a-z).
//Input : F
//Output : TRUE
//Input : &
//Output : FALSE
#include <stdio.h>
#define true 1
#define false 0
typedef int bool;
bool ChkAlpha(char ch)
{
    if((ch>=65 && ch <=90) ||(ch>=97 && ch<=122))
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
    bRet=ChkAlpha(cValue);
    if(bRet==true)
    {
        printf("It is character");
    }
    else
    {
        printf("It is not character");
    }
    return 0;
}
