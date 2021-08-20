// Accept a number from user and print  factors of the number
// input = int
// output = even factors

#include <stdio.h>
void DisplayFacotrs(int iNo)
{
    int i=0;
    if(iNo<=0)
    {
        iNo=-iNo;
    }
    for(i=1;i<iNo;i++)
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
    printf("Enter number\n");
    scanf("%d",&iVal);

    DisplayFacotrs(iVal);
    return 0;
}