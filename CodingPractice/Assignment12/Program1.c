//Accept number of rows and number of columns from user and display below
//pattern.
//Input : iRow = 4 iCol = 4
//Output : A B C D
//         A B C D
//         A B C D
//         A B C D
#include<stdio.h>
void Pattern(int iRow,int iCol)
{
    for(int i=1;i<=iRow;i++)
    {
        char ch='A';
        for(int j=1;j<=iCol;j++)
        {
            printf("%c ",ch);
            ch++;
        }
        printf("\n");
    }
}
int main()
{
    int iValue1 = 0;
    int iValue2 = 0;
    printf("Enter number of Rows and colums ");
    scanf("%d %d",&iValue1,&iValue2);
    Pattern(iValue1,iValue2);
    return 0;
}