//Write a program which 2 strings from user and concat second string
//after first string. (Implement strcat() function).
//Input : “Marvellous Infosystems”
//“Logic Building”
//Output : “Marvellous Infosystems Logic Building”
#include <stdio.h>

int StrCatX(char *src,char *dest)
{
    int iCnt=0;
    if(dest==NULL)
    {
        return 0;
    }

    while(*src !='\0')
    {
        src++;
    }
    *src=32;
    src++;
    while(*dest!='\0')
    {
        *src=*dest;
        src++;
        dest++;
    }
    *src='\0';
}
int main()
{
    char Arr[50]="Marvellous Infosystems";
    char Brr[30]="Logic Building";
    StrCatX(Arr,Brr);
    printf("%s",Arr);

    return 0;
}
