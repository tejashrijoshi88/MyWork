//Write a program which accept string from user and convert it into
//lower case.
//Input : “Marvellous Multi OS”
//Output : marvellous multi os
#include <stdio.h>

void StrlwrX(char *str)
{
    if(str==NULL)
    {
        return;
    }
    while(*str !='\0')
    {
        if(*str>='A' && *str<='Z')
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
    StrlwrX(Arr);
    printf("Updated string is  %s",Arr);
    return 0;
}
