// Accept number from user and check weather the number is perfect or not
// input = 12
// output = 1,2,3,4,6 = 16  -- false
// input = 6
// output = 1,2,3 = 6 -- true


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - CheckPerfect
// input - integer
// output - bool
// Desc - It is used to show if the number is perfect
// Date - 03/02/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
bool CheckPerfect(int iNo)
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
    if(iSum==iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//time complexity o(n/2)
int main()
{
    int iValue1=0;
    bool bRet=false;

    printf("Enter first number\n");
    scanf("%d",&iValue1);

    bRet= CheckPerfect(iValue1);
    if(bRet == true)
    {
        printf("Perfect number");
    }
    else
    {
        printf("Not perfect Number");
    }
}