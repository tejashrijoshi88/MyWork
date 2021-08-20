// Accept number from user and display its factors of that number
// input = 12
// output = 1,2,3,4,6
// input = 20
// output = 1,2,4,5,10


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - Factors
// input - integer
// output - factors
// Desc - It is used to display the factors of the number
// Date - 03/02/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
int Factors(int iNo)
{
    int i=0;
    if(iNo <0)
    {
        iNo = -iNo;
    }
    for(i = 1; i < iNo;i++)
    {
        if(iNo%i ==0)
        {
            printf("%d ",i);
        }
    }
}
// time complexity o(n)
int main()
{
    int iValue1=0;
    int iRet=0;

    printf("Enter first number\n");
    scanf("%d",&iValue1);

    Factors(iValue1);
}