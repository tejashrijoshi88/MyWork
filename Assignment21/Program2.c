//Accept Character from user and check whether it is capital or not
//(A-Z).
//Input : F
//Output : TRUE
//Input : d
//Output : FALSE
#include <stdio.h>
#define true 1
#define false 0
typedef int bool;
bool ChkCapital(char ch)
{
   
    if(ch>=65 && ch<=90)
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
    
    bRet=ChkCapital(cValue);
    if(bRet==true)
    {
        printf("It is capital");
    }
    else
    {
        printf("It is not capital");
    }

    return 0;
}
