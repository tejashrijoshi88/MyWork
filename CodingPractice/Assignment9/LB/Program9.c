// Accept marks from user and 
// input = first no: 15 second No : 5
// output = Yes
// input = first no: 15 second No : 7
// output = No

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
void ChkResult(int iMarks)
{
    /* 0-35 fail 
    35-50 third class
    50 -60 second class
    60 -70 first class
    70-100 first class with distinction
    */
    if(iMarks <0 || iMarks >100)
    {
        printf("Invalid marks");
        return;
    }
    if(iMarks >= 0 && iMarks <35)
    {
        printf("Fail");
    }
    else if(iMarks >=35 && iMarks < 50)
    {
        printf("Third Class");
    }
    else if(iMarks >=50 && iMarks < 60)
    {
        printf("Second Class");
    }
    else if(iMarks >=60 && iMarks < 70)
    {
        printf("First Class");
    }
    else if(iMarks >=70 && iMarks <=100 )
    {
        printf("First Class with distinction");
    }
    else
    {
        printf("Invalid Marks");
    }
}
int main()
{
    int iValue= 0;
    bool bRet= false;
    printf("Enter your marks\n");
    scanf("%d",&iValue);
    ChkResult(iValue);
    return 0;
}
