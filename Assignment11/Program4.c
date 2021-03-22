// Accept number of rows and number of columns from user and display
//below pattern.
//Input : iRow = 3 iCol = 4
//Output : * # * #
//         * # * #
//         * # * #

// Time Complexity O(n) where n is input number
#include <stdio.h>
void Pattern(int iRow,int iCol)
{
    for(int i=1;i<=iRow;i++)
    {
        for(int j=1;j<=iCol;j++)
        {
            if(j%2!=0)
            {
                printf("* ");
            }
            else
            {
                printf("# ");
            }
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