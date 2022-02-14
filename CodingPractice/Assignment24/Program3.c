//Write a program which accept string from user and toggle the case.
//Input : “Marvellous Multi OS”
//Output : mARVELLOUS mULTI os
#include <stdio.h>

void strToggle(char *str)
{
    if(str==NULL)
    {
        return;
    }
    while(*str !='\0')
    {
        if(*str>='a' && *str<='z')
        {
            *str=*str-32;
        }
        else if(*str>='A' && *str<='Z')
        {
            *str=*str+32;
        }
        str++;
    }
}
int main()
{
    char Arr[20];
    int iRet=0;
    printf("Enter string ");
    scanf("%[^'\n']s",Arr);
    strToggle(Arr);
    printf("Updated string is  %s",Arr);
    return 0;
}
