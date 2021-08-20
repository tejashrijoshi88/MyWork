//Write a program which accept string from user and count number of
//small characters.
//Input : “Marvellous”
//Output : 9
#include <stdio.h>

int CountCapital(char *str)
{
    if(str==NULL)
    {
        return 0;
    }
    int iCnt=0;
    while(*str !='\0')
    {
        if(*str>='a' && *str<='z')
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}
int main()
{
    char Arr[20];
    int iRet=0;
    printf("Enter string ");
    scanf("%[^'\n']s",Arr);
    iRet=CountCapital(Arr);
    printf("Count of small letters is %d",iRet);
    return 0;
}
