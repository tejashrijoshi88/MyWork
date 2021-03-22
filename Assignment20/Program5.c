//Accept N numbers from user and display summation of digits of each number.
//Input : N : 6
//Elements : 8225 665 3 76 953 858
//Output : 17 17 3 13 17 21
#include <stdio.h>
#include <stdlib.h>
void DigitsSum(int Arr[],int iLength)
{
    int i=0;
    int iDigit=0;
    int iDigitSum=0;
    int iNo=0;
    if(Arr==NULL || iLength==0)
    {
        return;
    }
    for(i=0;i<iLength;i++)
    {
        iDigitSum=0;
        iNo=Arr[i];
        while(iNo>0)
        {
            iDigit=iNo%10;
            iDigitSum=iDigitSum+iDigit;
            iNo=iNo/10;
        }
        printf("%d ",iDigitSum);
    }
}
int main()
{
    int iSize=0; int iCnt=0;
    int iRet=0;int iNo=0;
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

    DigitsSum(p,iSize);  
    free(p);
    return 0;
}
