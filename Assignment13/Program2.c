// Accept number from user and display below pattern.
// Input : iRow = 4 iCol = 4
// Output : * * * *      4,1 4,2 4,3 4,4
//          * * * #      3,1 3,2 3,3 3,4
//          * * # #      2,1 2,2 2,3 2,4
//          * # # #      1,1 1,2 1,3 1,4
#include <stdio.h>
void Pattern(int iRow,int iCol)
{
    int i,j;
    for(i=iRow;i>=1;i--)
    {
        for(j=1;j<=iCol;j++)
        {
            //if((i-j)>=0)
            if(i >= j)
            {
                printf("*\t");
            }
            else
            {
                printf("#\t");
            }
        }
        printf("\n");
    }
}
int main()
{
    int iVal1=0;
    int iVal2=0;
    printf("Enter the Number of rows: ");
    scanf("%d",&iVal1);
    printf("Enter the Number of cols: ");
    scanf("%d",&iVal2);
    Pattern(iVal1,iVal2);
    return 0;
}
