// Accept number and print that number of stars on screen
// input = int
// output = stars for given number

#include <stdio.h>
void Accept(int iNum)
{

    for(int i=1;i<=iNum;i++)
    {
        printf("*");
    }
}
int main()
{
    int iVal=0;
    iVal=5;
/*    printf("Enter number");
    scanf("%d",&iVal);
    */
    Accept(iVal);
    return 0;
}