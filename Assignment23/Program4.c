//Write a program which accept string from user and check whether
//it contains vowels in it or not.
//Input : “marvellous”
//Output : TRUE
//Input : “Demo”
//Output : TRUE
//Input : “xyz”
//Output : FALSE
#include <stdio.h>
#define true 1
#define false 0
typedef int bool;
bool ChkVowel(char *str)
{
   while(*str !='\0')
   {
       if(*str=='a'||*str=='A'||*str=='e'||*str=='E'||*str=='i'||*str=='I'||*str=='o'||*str=='O'||*str=='u'||*str=='U')
       {
           return true;
       }

       str++;
   }
    return false;
}
int main()
{
    char Arr[20];
    bool bRet=false;
    printf("Enter the character: ");
    scanf("%[^'\n']s",Arr);
    
    bRet=ChkVowel(Arr);
    if(bRet==true)
    {
        printf("String contains vowel");
    }
    else
    {
        printf("There is no vowel");
    }

    return 0;
}
