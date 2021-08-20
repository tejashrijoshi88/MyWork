// Accept number from user and display below pattern.
// Input : iRow = 4 iCol = 4
// Output : A B C D
//          a b c d
//          A B C D
//          a b c d
// time complexity O(n)
#include <stdio.h>


void Pattern(int iRow,int iCol)
{
    for(int i=1;i<=iRow;i++)
    {
        char cUpper='A';
        char cLower='a';
        for( int j=1;j<=iCol;j++)
        {
            if(i%2==0)
            {
                printf("%c ",cLower);
                cLower++;
            } 
            else
            {
                printf("%c ",cUpper);
                cUpper++;
            }          
        }
        printf("\n");
    }
}
int main()
{
    int iVal1=0;
    int iVal2=0;
    printf("Enter Number of rows and columns ");
    scanf("%d %d",&iVal1,&iVal2);
    Pattern(iVal1,iVal2);
    return 0;
}