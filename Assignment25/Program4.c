//Write a program which accept string from user and accept one
//character. Return index of last occurrence of that character.
//Input : “Marvellous Multi OS”
// M
//Output : 11
//Input : “Marvellous Multi OS”
// W
//Output : -1
//Input : “Marvellous Multi O
//e
//Output : 4 
#include <stdio.h>

int LastOccurance(char *str,char ch)
{
   if(str==NULL)
   {
       return 0;
   }
   int iCnt=0;
   int iLastOccurance=-1;
   while(str[iCnt] !='\0')
   {
       if(str[iCnt]==ch)
       {
          iLastOccurance=iCnt;
       }

       iCnt++;
   }
    return iLastOccurance;
}
int main()
{
    char Arr[20];
    char chValue='\0';
    int iRet=0;
    printf("Enter the string: ");
    gets(Arr);
    printf("Enter character ");
    scanf("%c",&chValue);
    iRet=LastOccurance(Arr,chValue);
    printf("last occurance of the character is %d",iRet);

    return 0;
}
