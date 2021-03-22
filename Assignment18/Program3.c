//Accept N numbers from user check whether that numbers contains 11 in
//it or not.
//Input : N : 6
//Elements : 85 66 11 80 93 88
//Output : 11 is present
//Input : N : 6
//Elements : 85 66 3 80 93 88
//Output : 11 is absent
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
bool Check(int Arr[],int iLength)
{
    int i=0;
    for(i=0;i<iLength;i++)
    {
        if(Arr[i]==11)
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
    bool iRet=false;
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
    iRet=Check(p,iSize);
    if(iRet==true)
    {printf("11 is present");}
    else
    {
        printf("11 is absent");
    }
    free(p);
    return 0;
}
