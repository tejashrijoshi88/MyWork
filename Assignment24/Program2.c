//Write a program which accept string from user and convert it into
//upper case.
//Input : “Marvellous Multi OS”
//Output : MARVELLOUS MULTI OS
#include <stdio.h>

void StruprX(char *str)
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
        str++;
    }
}
int main()
{
    char Arr[20];
    int iRet=0;
    printf("Enter string ");
    scanf("%[^'\n']s",Arr);
    StruprX(Arr);
    printf("Updated string is  %s",Arr);
    return 0;
}
