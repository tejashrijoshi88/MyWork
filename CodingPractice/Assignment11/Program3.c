// Accept number of rows and number of columns from user and display
//below pattern.
//Input : iRow = 3 iCol = 5
//Output : 5 4 3 2 1
//         5 4 3 2 1
//         5 4 3 2 1

// Time Complexity O(n)
#include <stdio.h>
void Pattern(int iRow,int iCol)
{
    for (int i=1;i<=iRow;i++)
    {
        for(int j=iCol;j>=1;j--)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
}
int main()
{
    int iVal1=0;
    int iVal2=0;
    printf("Enter number of rows and cols ");
    scanf("%d %d",&iVal1,&iVal2);
    Pattern(iVal1,iVal2);
    return 0;
}