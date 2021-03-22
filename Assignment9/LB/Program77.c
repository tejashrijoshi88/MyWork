/*
create static character array in main function 
Accept the string into that array
Pass the string to the function
function will perform the operation on that string
*/

#include<stdio.h>
void Display(char str[])
{
    printf("Characters of string are\n");
    while(*str!='\0')
    {
        printf("%c\n",*str);
        str++;
    }
}
int main()
{
    
    char Arr[40];
    printf("Enter your name");
    fgets(Arr,40,stdin);

    Display(Arr);
    return 0;
}