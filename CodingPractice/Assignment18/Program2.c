//Accept N numbers from user and return difference between frequency of
//even number and odd numbers.
//Input : N : 7
//Elements : 85 66 3 80 93 88 90
//Output : 1 (4 -3)
#include <stdio.h>
#include <stdlib.h>
int Frequency(int Arr[],int iLength)
{
    int iOddCount=0;
    int iEvenCount=0;
    int i=0;
    for(i=0;i<iLength;i++)
    {
        if(Arr[i]%2==0)
        {
            iEvenCount++;
        }
        else
        {
            iOddCount++;
        }
    }
    return (iEvenCount-iOddCount);
}
int main()
{
    int iSize=0; int iCnt=0;
    int iRet=0;
    int *p=NULL;
    printf("Enter the Number of rows: ");
    scanf("%d",&iSize);
    p=(int*)malloc(iSize*sizeof(int));
    if(p==NULL)
    {
        printf("Unable to allocate memory");
        scanf("%d",&iSize);
    }
    printf("Enter elements");
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("Enter element %d :",iCnt+1);
        scanf("%d",&p[iCnt]);
    }
    iRet=Frequency(p,iSize);
    printf("Difference between frequency is %d",iRet);
    free(p);
    return 0;
}
