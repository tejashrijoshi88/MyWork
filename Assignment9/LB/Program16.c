// Accept number from user and display addition of its factors
// input = 12
// output = 1,2,3,4,6 = 16
// input = 6
// output = 1,2,3 = 6


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - FactSum
// input - integer
// output - Sum of factors(integer)
// Desc - It is used to display sum of the factors of the number
// Date - 03/02/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
int FactSum(int iNo)
{
    int i=0;
    int iSum=0;
    if(iNo <0)
    {
        iNo = -iNo;
    }
    for(i = 1; i <= iNo/2;i++)
    {
        if(iNo%i ==0)
        {
            iSum= iSum+i;
        }
    }
    return iSum;
}
//time complexity o(n/2)
int main()
{
    int iValue1=0;
    int iRet=0;

    printf("Enter first number\n");
    scanf("%d",&iValue1);

    iRet= FactSum(iValue1);
    printf("Addition is %d",iRet);
}