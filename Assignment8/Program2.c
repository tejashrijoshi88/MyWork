// Accept a number from user and print numbers till that number on screen
// input = 8
// output =  1 2 3 4 5 6 7 8
// time complexity O(n)
#include <stdio.h>

void Display(int iNo)
{
    int i = 0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    for(i=1;i<=iNo;i++)
    {
        printf("%d ",i);
    }
}
int main()
{
    int iVal;
  
    printf("Enter Number ");
    scanf("%d",&iVal);
    Display(iVal);
    return 0;
}