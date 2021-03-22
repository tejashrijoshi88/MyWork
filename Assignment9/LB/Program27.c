// Accept number from user and check weather number os palindrome or not
// input = 57
// output = Number is not palindrome
// input = 121
// output - Numbe is palindrome


/*
start

end
*/
/////////////////////////////////////////////////////////////////////
// Function Name - IsPalindrome
// input - integer
// output - bool
// Desc - It is used to check if number is palindrome
// Date - 08/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
/*

*/
#include <stdio.h>
#include <stdbool.h>
bool IsPalindrome(int iNo)
{
    int iReverse=0;
    int iDigit=0;
    
    if(iNo<0)
    {
        iNo=-iNo;
    }
    int iNum=iNo;
    while(iNo>0)
    {
        iDigit = iNo%10;
        iReverse = (iReverse*10)+iDigit;
        iNo=iNo/10;
    }
    if(iNum==iReverse)
    {
        return true;
    }
    else{return false;}
    
}
int main()
{
    int iVal1=0;
    bool bRet=false;
    printf("Enter Number ");
    scanf("%d",&iVal1);
    bRet=IsPalindrome(iVal1);
    if(bRet==true)
    {
        printf("Number is palindrome");
    }
    else{printf("Number is not palindrome");}
    return 0;
}