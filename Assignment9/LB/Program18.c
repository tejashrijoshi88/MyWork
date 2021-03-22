// Accept number from user and check weather the number is prime
// input = 12
// output = false
// input = 13
// output = true


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - CheckPrime
// input - integer
// output - bool
// Desc - It is used to show if the number is prime
// Date - 03/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
bool CheckPrime(int iNo)
{
    int i=0;
    if(iNo <0)
    {
        iNo = -iNo;
    }
    for(i = 2; i <= iNo/2;i++)
    {
        if(iNo%i ==0)
        {
            break;
        }
    }
    if(i==(iNo/2)+1)
    {
        return true;
    }
    else{return false;}

}
//time complexity o(n/2)
int main()
{
    int iValue1=0;
    bool bRet=false;

    printf("Enter first number\n");
    scanf("%d",&iValue1);

    bRet= CheckPrime(iValue1);
    if(bRet == true)
    {
        printf("Prime number");
    }
    else
    {
        printf("Not prime Number");
    }
}