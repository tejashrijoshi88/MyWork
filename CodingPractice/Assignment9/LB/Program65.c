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
void DisplayEven(int Arr[],int iLength)
{
    if(Arr==NULL || iLength<=0)
    {
        return;
    }
    for(int i;i<iLength;i++)
    {
        if(Arr[i]%2==0)
        {
            printf("%d ",Arr[i]);
        }
    }
}
int main()
{
    int *arr=NULL;
    int iCnt=0,iSize=0;
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
    DisplayEven(arr,iSize);
    free(arr);
    return 0;
}
