//Accept N numbers from user and return frequency of 11 form it.
//Input : N : 6
//Elements : 85 66 3 15 93 88
//Output : 0
//Input : N : 6
//Elements : 85 11 3 15 11 111
//Output : 2
#include <stdio.h>
#include <stdlib.h>
int Frequency(int Arr[],int iLength)
{
    int iFrequency=0;
    int i=0;
    for(i=0;i<iLength;i++)
    {
        if(Arr[i]==11)
        {
            iFrequency++;
        }
    }
    return (iFrequency);
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
    printf("frequency of 11 is %d",iRet);
    free(p);
    return 0;
}
