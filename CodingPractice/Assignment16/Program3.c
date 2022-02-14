// Accept number from user and display below pattern.
//Input : iRow = 6 iCol = 6
//Output : * * * * * *
//         *       * *
//         *     *   *
//         *   *     *
//         * *       *
//         * * * * * *
#include <stdio.h>
void Pattern(int iRow,int iCol)
{
    int i,j;
    for(i=iRow;i>=1;i--)
    {
        for(j=1;j<=iCol;j++)
        {
            if(i==j || i==1|| j==1 ||i==iRow||j==iCol)
            {
                printf("*\t");
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }
}
int main()
{
    int iVal1=0;
    int iVal2=0;
    printf("Enter the Number of rows and columns: ");
    scanf("%d %d",&iVal1,&iVal2);

    Pattern(iVal1,iVal2);
    return 0;
}
