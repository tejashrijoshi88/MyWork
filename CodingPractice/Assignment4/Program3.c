// Accept a number from user and print all non factors of the number
// input = int
// output = even factors

#include <stdio.h>
void NonFact(int iNo)
{
    int i=0;
    if(iNo<=0)
    {
        iNo=-iNo;
    }
    for(i=1;i<iNo;i++)
    {
        if(iNo%i!=0)
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

    NonFact(iVal);
    return 0;
}