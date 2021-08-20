// Accept number of rows and number of columns from user and display below pattern.
//Input : iRow = 4 iCol = 3
//Output : 1 2 3
//         1 2 3
//         1 2 3
//         1 2 3
// time complexity O(n)
#include <stdio.h>


void Pattern(int iRow,int iCol)
{
    for(int i=1;i<=iRow;i++)
    {
        for(int j =1;j<=iCol;j++)
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
    printf("Enter Number of rows and columns");
    scanf("%d %d",&iVal1,&iVal2);
    Pattern(iVal1,iVal2);
    return 0;
}