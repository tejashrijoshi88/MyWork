//Write a program which accept string from user reverse that string
//in place.
//Input : “abcd”
//Output : “dcba”
//Input : “abba”
//Output : “abba”
#include <stdio.h>

void StrRevX(char *str)
{
    int iStart=0;
    int iEnd=0;
    if(str==NULL)
    {
        return;
    }
    while(str[iEnd]!='\0')
    {
        iEnd++;
    }
    iEnd--;
    while(iStart<iEnd)
    {
        char temp=str[iStart];
        str[iStart]=str[iEnd];
        str[iEnd]=temp;
        iStart++;
        iEnd--;
    }

}
int main()
{
    char Arr[20];
    int iRet=0;
    printf("Enter the String: ");
    scanf("%[^'\n']s",Arr);
    
    StrRevX(Arr);
    printf("updated string  %s",Arr);

    return 0;
}
