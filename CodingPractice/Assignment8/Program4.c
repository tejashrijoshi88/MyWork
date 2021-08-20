// Write a program which accepts N from user and print all odd numbers up to N.
// integer = 18
// output = 1 3 5 7 9 11 13 15 17
// Time Complexity O(n)
#include <stdio.h>
void OddDisplay(int iNo)
{
    if(iNo<=0)
    {
        iNo=-iNo;
    }

    for(int i=1;i<=iNo;i=i+2)
    {
        printf("%d ",i);
    }
}
int main()
{
    int iVal=0;

    printf("Enter number ");
    scanf("%d",&iVal);

    OddDisplay(iVal);
    return 0;
}