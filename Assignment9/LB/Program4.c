// accept number from user and display all  numbers till input number
/*
start
    Accept one number as No
    if Number is negative
        then convert it to positive
    create one counter as cnt and set it to 1
    iterate till counter is less than or equal to the number
        print the value of counter on screen
        increment the value of counter by 1
    countinue
end
*/
#include <stdio.h>
void Display(int iValue) // 5
{
    if(iValue==0) // input updater
    {
        return;
    }
    if(iValue<0) // input updater
    {
        iValue=-iValue;
    }
    //      1      2       3
    for(int i=1;i<=iValue;i++)
    {
        printf("%d\n",i);//4
    }
    // 1 (2 4 3) (2 4 3) (2 4 3) (2 4 3) 2 
    // 1   2       3       4        5
}
int main()// entry point
{
    int iNo=0;
    printf("Take the input number\n");
    scanf("%d",&iNo);

    Display(iNo);

    return 0;
}

