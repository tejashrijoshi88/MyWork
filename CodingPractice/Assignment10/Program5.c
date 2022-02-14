// Accept number from user and display below pattern.
// Input : 8
// Output : 2 4 6 8 10 12 14 16

// time complexity O(n)

#include <stdio.h>

int Pattern(int iNo)
{
    for(int i =1;i<=iNo;i++)
    {
        printf("%d ",(2*i));
    }
}

int main()
{
    int iValue=0;

    printf("Enter number ");
    scanf("%d",&iValue);
    Pattern(iValue);
}


