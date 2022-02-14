// Accept n numbers from user and a seperate number display index of first occurance of the number
/////////////////////////////////////////////////////////////////////
// Function Name - FirstOccurance
// input - 10 20 30 10 ,10
// output - 0
// Desc - Displays index of first occurance of the number
// Date - 17/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
int FirstOccurance(int Arr[],int iLength,int iValue)
{
    if(Arr==NULL || iLength<=0)
    {
        return -1;
    }
    int i=0;
    for(i=0;i<iLength;i++)
    {
        if(Arr[i]==iValue)
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
    iRet=FirstOccurance(arr,iSize,iNo);
    if(iRet==-1)
    {
        printf("Number not found");
    }
    else    
    {
        printf("First Occurance is %d ",iRet);
    }
    free(arr);
    return 0;
}
