// Accept a number from user and print that number of stars on screen
// input = int
// output = stars for given number

#include <stdio.h>
void display(int iNo)
{
    int iCnt=0;
    for (iCnt=1;iCnt<=iNo;iCnt++)
    {
        printf("*");
    }
}
int main()
{
    int iVal=0;
    printf("Enter number\n");
    scanf("%d",&iVal);

    display(iVal);
    return 0;
}