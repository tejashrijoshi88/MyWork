// Accept a number from user and display digits in reverse order
// input = int
// output = digits
// time complexity O(n)
#include <stdio.h>
void DisplayReverse(int iNo)
{
    int iDigit=0;
    if(iNo<0)
    {
        iNo = -iNo;
    }
    while(iNo >0)
    {
        iDigit = iNo%10;
        printf("%d ",iDigit);
        iNo=iNo/10;
    }
}
int main()
{
    int iVal=0;
    printf("Enter the Number");
    scanf("%d",&iVal);
    DisplayReverse(iVal);
    return 0;
}
