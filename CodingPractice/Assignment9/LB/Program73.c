// Accept n numbers from user and return min number
/////////////////////////////////////////////////////////////////////
// Function Name - Minimum
// input - 9 20 30 10 ,10
// output - 9
// Desc - Displays min number
// Date - 17/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
int Minimum(int Arr[],int iLength)
{
    if(Arr==NULL || iLength<=0)
    {
        return -1;
    }
    int i=0;
    int iMin=Arr[0];
    for(i=0;i<iLength;i++)
    {
        if(Arr[i]<iMin)
        {
            iMin=Arr[i];
        }
    }
    return iMin;
    
}
int main()
{
    int *arr=NULL;
    int iCnt=0,iSize=0;int iRet=0;
    int iNo=0;
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
    iRet=Minimum(arr,iSize);
    printf("Min number is %d ",iRet);

    free(arr);
    return 0;
}
