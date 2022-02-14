// Accept n numbers from user and display given numbers


/////////////////////////////////////////////////////////////////////
// Function Name - Display
// input - array
// output - numbers
// Desc - Displays numbers o array
// Date - 16/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
void Display(int Arr[],int iSize)
{ 
    printf("Numbers are:");
    for(int i=0;i<iSize;i++)
    {
        printf("%d ",Arr[i]);
    }
}
int main()
{
    int *arr=NULL;
    int iLength=0;int iCnt=0;
    printf("Number of elememnts");
    scanf("%d",&iLength);

    arr=(int*)malloc(iLength*sizeof(int));
    printf("Enter the elements");
    for(iCnt=0;iCnt<iLength;iCnt++)
    {
       scanf("%d",&arr[iCnt]);
    }
    Display(arr,iLength);
    free(arr);
    return 0;
}