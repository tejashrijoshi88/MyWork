//Write a program which accept string from user and display it inn
//reverse order.
//Input : “MarvellouS”
//Output : “SuollevraM”
#include <stdio.h>

void Reverse(char *str)
{
    char* start;
    char* end;
    if(str==NULL)
    {
        return;
    }
    start=end=str;
    while(*end !='\0')
    {
        end++;
    }
    end--;
    while(start<end)
    {
        char temp=*start;
        *start=*end;
        *end=temp;
        end--;
        start++;
    }
}
int main()
{
    char Arr[20];
    printf("Enter the String: ");
    scanf("%[^'\n']s",Arr);
    
    Reverse(Arr);
    printf("Reversed string is %s",Arr);

    return 0;
}
