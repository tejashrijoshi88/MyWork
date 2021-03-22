/*
create static character array in main function 
Accept the string into that array
Pass the string to the function
function will perform the operation on that string
*/

#include<stdio.h>
int StrLenX(char str[])
{
    int iCnt=0;
    
    while(str[iCnt]!='\0')
    {
        iCnt++;
    }
    return iCnt;
}
int main()
{
    
    char Arr[40];
    int iRet=0;
    printf("Enter your name");
    //(Arr,40,stdin);
    scanf("%[^'\n']s",Arr);
    iRet=StrLenX(Arr);
    printf("%d",iRet);
    return 0;
}