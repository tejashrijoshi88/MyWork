//Write a program which accept string from user and accept one
//character. Return frequency of that character.
//Input : “Marvellous Multi OS”
// M
//Output : 2
//Input : “Marvellous Multi OS”
// W
//Output : 0 
#include <stdio.h>

int countChar(char *str,char ch)
{
    if(str==NULL)
    {
        return 0;
    }
    int iCnt=0;
    while(*str !='\0')
    {
        if(*str==ch)
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
    char chValue='\0';
    int iRet=0;
    printf("Enter string ");
    gets(Arr);
    printf("Enter character ");
    scanf("%c",&chValue);
    iRet=countChar(Arr,chValue);
    printf("Frequency of character is  %d",iRet);
    return 0;
}
