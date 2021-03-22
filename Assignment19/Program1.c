//Accept N numbers from user and accept one another number as NO ,
//check whether NO is present or not.
//Input : N : 6
//NO: 66
//Elements : 85 66 3 66 93 88
//Output : TRUE
//Input : N : 6
//NO: 12
//Elements : 85 11 3 15 11 111
//Output : FALSE
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
bool Check(int Arr[],int iLength,int ivalue)
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
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int iSize=0; int iCnt=0;
    bool iRet=false;int iNo=0;
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
    iRet=Check(p,iSize,iNo);
    if(iRet==true)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    
    free(p);
    return 0;
}
