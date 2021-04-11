//Accept Character from user and check whether it is small case or not
//(a-z).
//Input : F
//Output : false
//Input : d
//Output : true
#include <stdio.h>
#define true 1
#define false 0
typedef int bool;
bool ChkCapital(char ch)
{
   
    if(ch>=97 && ch<=122)
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
        printf("It is small case character");
    }
    else
    {
        printf("It is not small case character");
    }

    return 0;
}
