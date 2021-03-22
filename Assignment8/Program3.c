// Write a program which accepts number and displays its number line
// input = -4
// output =  -4 -3 -2 -1 0 1 2 3 4
// time complexity O(n)
#include <stdio.h>

void Display(int iNo)
{
    int i =0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    for(i=-iNo;i<=iNo;i++)
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