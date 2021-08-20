// Write a program to accept number from user and print that number of $ and * on screen
// Input : 5
// Output : $ * $ * $ * $ * $ *
//Input : 3
//Output : $ * $ * $ *
//Input : -3
//Output : $ * $ * $ *
// time complexity O(n)
#include <stdio.h>
void Pattern(int iNo)
{
    int i =0;
    for(i=1;i<=iNo;i++)
    {
        printf("$ * ");
    }
    
}
int main()
{
    int iVal=0;
    int iRet=0;
    printf("Enter the Number ");
    scanf("%d",&iVal);
    Pattern(iVal);
    return 0;
}
