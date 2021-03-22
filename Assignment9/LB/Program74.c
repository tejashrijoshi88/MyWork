// Accept n numbers from user and check if 11 exists or not
/////////////////////////////////////////////////////////////////////
// Function Name - Search
// input - 9 11 30 10 ,10
// output - true
// Desc - Check if 11 exists
// Date - 17/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
# include<stdbool.h>
bool Search(int Arr[],int iLength)
{
    if(Arr==NULL || iLength<=0)
    {
        return -1;
    }
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
    int *arr=NULL;
    int iCnt=0,iSize=0;bool iRet=false;
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
    iRet=Search(arr,iSize);
    if(iRet==true)
    {
        printf("number 11 present in array..");
    }
    else
    {
        printf("Number 11 does not present in array..");
    }
    free(arr);
    return 0;
}
