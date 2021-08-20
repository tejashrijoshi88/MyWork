/*
create static character array in main function 
Accept the string into that array
Pass the string to the function
function will perform the operation on that string
*/

#include<stdio.h>
int CcountA(char str[])
{
    int iCnt=0;
    if(str==NULL)
    {
        return 0;
    }
    while(*str!='\0')
    {
        if(*str=='a' || *str=='A')
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}
int main()
{
    
    char Arr[40];
    int iRet=0;
    printf("Enter your name ");
    //(Arr,40,stdin);
    scanf("%[^'\n']s",Arr);
    iRet=CcountA(Arr);
    printf("%d",iRet);
    return 0;
}