// Accept n numbers from user and display even numbers


/////////////////////////////////////////////////////////////////////
// Function Name - DisplayEvenCount
// input - array
// output - numbers
// Desc - Displays frequency of     even numbers
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
int DisplayEvenCount(int Arr[],int iLength)
{
    if(Arr==NULL || iLength<=0)
    {
        return -1;
    }
    int iCount=0;
    for(int i=0;i<iLength;i++)
    {
        if(Arr[i]%2==0)
        {
            iCount++;
        }
    }
    return iCount;
}
int main()
{
    int *arr=NULL;
    int iCnt=0,iSize=0;int iRet=0;
    printf("Enter number of elemrnts");
    scanf("%d",&iSize);

    arr=(int*)malloc(iSize*sizeof(int));
    if(arr==NULL)
    {
        printf("Unable to allocate memory");
        return -1;
    }
    printf("Enter elements");
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        scanf("%d",&arr[iCnt]);
    }
    iRet=DisplayEvenCount(arr,iSize);
    printf("frequeny %d",iRet);
    free(arr);
    return 0;
}
