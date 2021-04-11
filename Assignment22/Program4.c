//Accept Character from user and check whether it is special symbol
//or not (!, @, #, $, %, ^, &, *).
//Input : %
//Output : TRUE
//Input : d
//Output : FALSE
#include <stdio.h>
#define true 1
#define false 0
typedef int bool;
bool ChkSpecial(char ch)
{
   
    if(ch== 33 || ch==64 || ch==35 || ch==36 || ch==37 || ch==94 ||ch==38 || ch==42)
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
    
    bRet=ChkSpecial(cValue);
    if(bRet==true)
    {
        printf("It is special character");
    }
    else
    {
        printf("It is not special character");
    }

    return 0;
}
