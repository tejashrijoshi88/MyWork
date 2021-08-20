// Accept number from user and display below pattern.
// Input : 5
// Output : A B C D E
// time complexity O(n) - n is input number
#include <stdio.h>
void Pattern(int iNo)
{
    for(int i =65;i<(65+iNo);i++)
    {
        printf("%c ",i);
    }
}
int main()
{
    int iVal=0;
    printf("Enter the Number ");
    scanf("%d",&iVal);
    Pattern(iVal);
    return 0;
}
