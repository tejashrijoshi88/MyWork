// Accept Nuber from user and print that number of stars
// input = int
// output = stars for given number

#include <stdio.h>
void Display(int iNo)
{
    
    while (iNo>0)
    {
        printf("*");
        iNo--;
    }
    
}
int main()
{
    int iVal=0;
    printf("Enter Number");
    scanf("%d",&iVal);
    Display(iVal);
    return 0;
}