// Accept number from user and display table
// input = 5
// output = 5 10 15 20 25 30 35 40 45 50


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - ChkDivisible
// input - integer,integer
// output - boolean
// Desc - It is used to check weather first number is divisible by second number
// Date - 03/01/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
void DisplayTable(int iNo)
{   
    if(iNo < 0)
    {
        iNo=-iNo;
    }
    for (int i= 1 ; i<=10;i++)
    {
        printf("%d ",(iNo*i));
    }

}
int main()
{
    int iValue= 0;
    printf("Enter Number\n");
    scanf("%d",&iValue);
    DisplayTable(iValue);
    return 0;
}

