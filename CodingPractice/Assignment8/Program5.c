// Write a program which accept N and print first 5 multiples of N.
// input = 4
// output = 4 8 12 16 20
// time complexity O(1)

#include <stdio.h>

void MultipleDisplay(int iNo)
{
    if(iNo<0)
    {
        iNo=-iNo;
    }
    for(int i =1;i<=5;i++)
    {
        printf("%d ",(i*iNo));
    }

}

int main()
{
    int iValue=0;


    printf("Enter number ");
    scanf("%d",&iValue);
    MultipleDisplay(iValue);
    return 0;
}


