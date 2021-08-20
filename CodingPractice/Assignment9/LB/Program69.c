// Accept n numbers from user and a seperate number display count of that number
/////////////////////////////////////////////////////////////////////
// Function Name - DisplayCount
// input - array, number
// output - number
// Desc - Displays count of number in array
// Date - 17/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
int Frequency(int Arr[],int iLength,int iValue)
{
    if(Arr==NULL || iLength<=0)
    {
        return -1;
    }
    int iCount=0;
    for(int i=0;i<iLength;i++)
    {
        if(Arr[i]==iValue)
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

    printf("Enter number you want to search");
    scanf("%d",&iNo);
    iRet=Frequency(arr,iSize,iNo);
    printf("Frequency is %d ",iRet);
    free(arr);
    return 0;
}
