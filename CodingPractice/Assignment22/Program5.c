//Accept character from user and display its ASCII value in decimal,
//octal and hexadecimal format.
#include <stdio.h>

void Display(char ch)
{
    printf("Decimal\t%d\nOctal\t%o\nHexaDecimal\t%X",ch,ch,ch);
}
int main()
{
    char cValue='\0';
    printf("Enter the character: ");
    scanf("%c",&cValue);
    
    Display(cValue);


    return 0;
}
