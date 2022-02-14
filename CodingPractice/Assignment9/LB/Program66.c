// Accept n numbers from user and display even numbers


/////////////////////////////////////////////////////////////////////
// Function Name - DisplayEven
// input - array
// output - numbers
// Desc - Displays numbers o array
// Date - 16/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
int DisplaySum(int Arr[],int iLength)
{
    if(Arr==NULL || iLength<=0)
    {
        return -1;
    }
    int iSum=0;
    for(int i=0;i<iLength;i++)
    {
        iSum=iSum+Arr[i];
    }
    return iSum;
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
    iRet=DisplaySum(arr,iSize);
    printf("Sum is %d ",iRet);
    free(arr);
    return 0;
}
