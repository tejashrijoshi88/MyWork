// Accept number from user and return its factorial
// input = 4
// output = 4*3*2*1=24


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - Fact
// input - integer
// output - factorial
// Desc - It is used to calculate the factorial of the number
// Date - 03/02/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
int Fact(int iNo)
{
    int iFactorial=1;
    if(iNo <0)
    {
        iNo=-iNo;
    }
    while(iNo>0)
    {
        iFactorial = iFactorial*iNo;
        iNo--;
    }
    return iFactorial;

}
int main()
{
    int iValue1=0,iValue2=0;
    int iRet=0;

    printf("Enter first number\n");
    scanf("%d",&iValue1);

    iRet = Fact(iValue1);
    printf("The factorial of %d is %d",iValue1,iRet);
}