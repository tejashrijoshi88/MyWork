//Accept character from user. If character is small display its
//corresponding capital character, and if it small then display its
//corresponding capital. In other cases display as it is.
//Input : Q
//Output : q
//Input : m
//Output : M
//Input : 4
//Output : 4
//Input : %
//Output : %
#include <stdio.h>
#define true 1
#define false 0
typedef int bool;
void Display(char ch)
{
   
    if(ch>=65 && ch<=90)
    {
        printf("%c",ch+32);
    }
    else if(ch>=97 && ch<=122)
    {
        printf("%c",ch-32);
    }
    else
    {
        printf("%c",ch);
    }
}
int main()
{
    char cValue='\0';
    bool bRet=false;
    printf("Enter the character: ");
    scanf("%c",&cValue);
    Display(cValue);

    return 0;
}
