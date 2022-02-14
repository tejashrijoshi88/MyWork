//Write a program which accept string from user and return
//difference between frequency of small characters and frequency of
//capital characters.
//Input : “MarvellouS”
//Output : 6 (8-2)
#include <stdio.h>

int Difference(char *str)
{
    int iCntCap=0;
    int iCntSmall=0;
    if(str==NULL)
    {
        return 0;
    }
    while(*str != '\0')
    {
        if(*str >='A' && *str<='Z')
        {
            iCntCap++;
        }
        else if(*str >='a' && *str<='z')
        {
            iCntSmall++;
        }
        str++;
    }
    return iCntSmall-iCntCap;
}
int main()
{
    char Arr[20];
    int iRet=0;
    printf("Enter the string: ");
    scanf("%[^'\n']s",Arr);
    iRet=Difference(Arr);
    printf("The difference is %d",iRet);
    return 0;
}
