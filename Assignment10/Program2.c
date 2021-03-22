// Accept number from user and display below pattern.
// Input : 5
// Output : 5 # 4 # 3 # 2 # 1 #
// time complexity O(n)
#include <stdio.h>


void Pattern(int iNo)
{
    for(int i=iNo;i>=1;i--)
    {
        printf("%d # ",i);

    }
}
int main()
{
    int iVal;
    printf("Enter Number ");
    scanf("%d",&iVal);
    Pattern(iVal);
    return 0;
}