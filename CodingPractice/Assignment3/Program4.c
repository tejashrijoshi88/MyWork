// Accept one character from user and convert case of that character
// input = char  (a)
// output = char  (A)

#include <stdio.h>

char DisplayConvert(char cValue)
{
    if(cValue >= 65 && cValue <= 90)
    {
        printf("%c",cValue+32);
    }
    else if(cValue >=97 && cValue <=122)
    {
        printf("%c",cValue - 32);
    }
}
int main()
{

    char cValue='\0';
    printf("Enter Character\n");
    scanf("%c",&cValue);
    DisplayConvert(cValue);
    return 0;
}