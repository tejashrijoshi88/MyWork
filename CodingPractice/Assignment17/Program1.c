//Accept N numbers from user and return difference between summation
//of even elements and summation of odd elements.
//Input : N : 6
//Elements : 85 66 3 80 93 88
//Output : 53 (234 - 181)
#include <stdio.h>
#include <stdlib.h>
int Difference(int Arr[],int Length)
{
    int EvenSum=0;
    int OddSum=0;
    if(Arr==NULL || Length==0)
    {
        return -1;
    }
    for(int i=0;i<Length;i++)
    {
        if(Arr[i]%2==0)
        {
            EvenSum=EvenSum+Arr[i];
        }
        else
        {
            OddSum=OddSum+Arr[i];
        }
    } 
    return (EvenSum-OddSum);
}
int main()
{
    int iSize=0;int iRet=0;int iCnt=0;
    int *p=NULL;
    printf("Enter Number of Elemens::");
    scanf("%d",&iSize);
    p = (int *)malloc(iSize * sizeof(int));
    if(p == NULL)
    {
    printf("Unable to allocate memory");
    return -1;
    }
    printf("Enter %d elements ",iSize);
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("Enter Element : %d ::",iCnt+1);
        scanf("%d",&p[iCnt]);
    }
    iRet=Difference(p,iSize);
    printf("Result is %d",iRet);
    free(p);
    return 0;
}
