// Accept number of rows and columns from user and display below pattern.
//Input : iRow = 3 iCol = 5
//Output : A A A A A
//         B B B B B
//         C C C C C

// Time Complexity O(n)
#include <stdio.h>
void Pattern(int iRow,int iCol)
{
    for(int i=65;i<(65+iRow);i++)
    {
        for(int j=1;j<=iCol;j++)
        {
            printf("%c ",i);
        }
        printf("\n");
    }
}
int main()
{
    int iVal1=0;
    int iVal2=0;
    printf("Enter number of rows and columns ");
    scanf("%d %d",&iVal1,&iVal2);
    Pattern(iVal1,iVal2);
    return 0;
}