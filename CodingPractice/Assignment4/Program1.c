// Accept a number from user and print multplication of factors of the number
// input = int
// output = even factors

#include <stdio.h>
int MultFact(int iNo)
{
    int i=0;
    int iMul=1;
    if(iNo<=0)
    {
        iNo=-iNo;
    }
    for(i=1;i<iNo;i++)
    {
        if(iNo%i==0)
        {
            iMul= iMul*i;
        }
    }
    return iMul;

}
int main()
{
    int iVal=0;
    int iRet=0;
    printf("Enter number\n");
    scanf("%d",&iVal);

    iRet=MultFact(iVal);
    printf("Output %d",iRet);
    return 0;
}