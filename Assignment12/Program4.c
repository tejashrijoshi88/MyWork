// Accept number of rows and columns from user and display below pattern.
//Input : iRow = 4 iCol = 5
//Output : 4 4 4 4 4
//         3 3 3 3 3
//         2 2 2 2 2
//         1 1 1 1 1

// Time Complexity O(n)
#include <stdio.h>
void Pattern(int iRow,int iCol)
{
    for(int i=iRow;i>=1;i--)
    {
        for(int j=1;j<=iCol;j++)
        {
            printf("%d ",i);
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