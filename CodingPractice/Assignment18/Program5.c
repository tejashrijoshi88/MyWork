//Accept N numbers from user and accept one another number as NO ,
//return frequency of NO form it.
//Input : N : 6
//NO: 66
//Elements : 85 66 3 66 93 88
//Output : 2
//Input : N : 6
//NO: 12
//Elements : 85 11 3 15 11 111
//Output : 0
#include <stdio.h>
#include <stdlib.h>
int Frequency(int Arr[],int iLength,int iValue)
{
    int iFrequency=0;
    int i=0;
    for(i=0;i<iLength;i++)
    {
        if(Arr[i]==iValue)
        {
            iFrequency++;
        }
    }
    return (iFrequency);
}
int main()
{
    int iSize=0; int iCnt=0;
    int iRet=0;int iNo=0;
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
    printf("Enter the number");
    scanf("%d",&iNo);
    iRet=Frequency(p,iSize,iNo);
    printf("frequency of %d is %d",iNo,iRet);
    free(p);
    return 0;
}
