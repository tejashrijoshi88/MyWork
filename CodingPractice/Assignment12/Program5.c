// Accept number of rows and columns from user and display below pattern.
//Input : iRow = 3 iCol = 4
//Output : 1 2  3  4
//         5 6  7  8
//         9 10 11 12

// Time Complexity O(n)
#include <stdio.h>
void Pattern(int iRow,int iCol)
{
    int iCnt=1;
    for(int i=iRow;i>=1;i--)
    {
        for(int j=1;j<=iCol;j++)
        {
            printf("%d ",iCnt);
            iCnt++;
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