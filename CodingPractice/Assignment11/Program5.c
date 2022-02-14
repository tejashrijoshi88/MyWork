// Accept number of rows and cols from user and display below pattern.
//Input : iRow = 3 iCol = 4
//Output : 1 1 1 1
//         2 2 2 2
//         3 3 3 3
//         4 4 4 4


// time complexity O(n)

#include <stdio.h>

void Pattern(int iRow,int iCol)
{
    for(int i=1;i<=iRow;i++)
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
    int iValue1=0;
    int iValue2=0;
    printf("Enter number of rows and columns");
    scanf("%d %d",&iValue1,&iValue2);
    Pattern(iValue1,iValue2);
}


