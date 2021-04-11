//Write a program which accept string from user and accept one
//character. Check whether that character is present in string or not.
//Input : “Marvellous Multi OS”
// e
//Output : TRUE
//Input : “Marvellous Multi OS”
// W
//Output : FALSE
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;
bool chkChar(char *str,char ch)
{
    
    if(str==NULL)
    {
        return 0;
    }
    while(*str !='\0')
    {
        if(*str==ch)
        {
            return true;
        }
        str++;
    }
    return false;
}
int main()
{
    char Arr[20];
    char chValue='\0';
    int d=0;
    bool iRet=false;

    printf("Enter string ");
    gets(Arr);
    printf("Enter the character: ");
    scanf("%c",&chValue);



  
    iRet=chkChar(Arr,chValue);
    if(iRet==true)
    {
        printf("Character present in the string");
    }
    else
    {
        printf("character not present in the string");
    }
    return 0;
}
