// Accept number from user and display below pattern.
//Input : 5
//Output : 1 * 2 * 3 * 4 * 5 *

// Time Complexity O(n)
#include <stdio.h>
int Pattern(int iNo)
{
    for(int i =1;i<=iNo;i++)
    {
        printf("%d * ",i);
    }
}
int main()
{
    int iVal=0;
    printf("Enter number ");
    scanf("%d",&iVal);
    Pattern(iVal);
    return 0;
}