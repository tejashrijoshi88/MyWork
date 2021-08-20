/*
create static character array in main function 
Accept the string into that array
Pass the string to the function
function will perform the operation on that string
*/

#include<stdio.h>
int main()
{
    
    char Arr[40];
    printf("Enter your name");
    scanf("%[^'\n']s",Arr);
    //fgets(Arr,40,stdin);
    //gets(Arr);
    //scanf("%s",Arr);
    printf("your name is : %s\n",Arr);
    return 0;
}