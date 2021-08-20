// Accept a number from user and print  factors of the number in decreasing order
// input = int
// output =  factors

#include <stdio.h>
void FactRev(int iNo)
{
    int i=0;
    if(iNo<=0)
    {
        iNo=-iNo;
    }
    for(i=iNo-1;i>0;i--)
    {
        if(iNo%i==0)
        {
            printf("%d ",i);
        }
    }

}
int main()
{
    int iVal=0;
    printf("Enter number ");
    scanf("%d",&iVal);

    FactRev(iVal);
    return 0;
}