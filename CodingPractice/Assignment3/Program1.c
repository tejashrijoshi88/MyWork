// Accept a number from user and print that number of even numbers on screen
// input = int (7)
// output = even numbers (2 4 6 8 10 12 14)

#include <stdio.h>
void PrintEven(int iNo)
{
    if(iNo<=0)
    {
        return;
    }
    int icount=0;
    for(icount=1;icount<=iNo;icount++)
    {
        printf("%d ",icount*2);
    }
}
int main()
{
    int iVal=0;
    printf("Enter number\n");
    scanf("%d",&iVal);

    PrintEven(iVal);
    return 0;
}