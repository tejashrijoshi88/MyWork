//Write a program which accept string from user and copy small
//characters of that string into another string.
//Input : “Marvellous multi OS”
//Output : “arvellous multi”
#include <stdio.h>

void StrCpySmall(char *src,char *dest)
{
    if(src==NULL)
    {
        return;
    }
    while(*src !='\0')
    {
       if((*src>='a' && *src<='z')||*src==32)
       {
          *dest=*src;
          dest++;
       }

       src++;
    }
    dest='\0';
}
int main()
{
    char Arr[30];
    char Brr[30];
    printf("Enter the character: ");
    scanf("%[^'\n']s",Arr);
    StrCpySmall(Arr,Brr);
    printf("%s",Brr);

    return 0;
}
