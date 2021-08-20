//Accept N numbers from user and accept one another number as NO ,
//return index of first occurrence of that NO.
//Input : N : 6
//NO: 66
//Elements : 85 66 3 66 93 88
//Output : 1
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
int FirstOcc(int Arr[],int iLength,int ivalue)
{
    int i=0;
    for(i=0;i<iLength;i++)
    {
        if(Arr[i]==ivalue)
        {
            break;
        }
    }
    if(i==iLength)
    {
        return -1;
    }
    else
    {
        return i;
    }
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
    printf("Enter Number");
    scanf("%d",&iNo);
    iRet=FirstOcc(p,iSize,iNo);
    printf("First occurance of the number is %d",iRet);
    
    free(p);
    return 0;
}
