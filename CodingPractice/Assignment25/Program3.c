//Write a program which accept string from user and accept one
//character. Return index of first occurrence of that character.
//Input : “Marvellous Multi OS”
// M
//Output : 0
//Input : “Marvellous Multi OS”
// W
//Output : -1
//Input : “Marvellous Multi OS”
// e
//Output : 4
#include <stdio.h>

int FirstChar(char *str,char ch)
{
    if(str==NULL)
    {
        return 0;
    }
    int iCnt=0;
    int iFound=0;
    while(str[iCnt] !='\0')
    {    
        if(str[iCnt]==ch)
        {
            iFound=1;
            break;
        }
        iCnt++;
    }
    if(iFound==1)
    {
        return iCnt;
    }
    else
    {
        return -1;
    }
}
int main()
{
    char Arr[20];
    int iRet=0;
    char chValue='\0';
    printf("Enter string ");
    gets(Arr);
    printf("Enter character ");
    scanf("%c",&chValue);
    iRet=FirstChar(Arr,chValue);
    printf("index of first char is  %d",iRet);
    return 0;
}
