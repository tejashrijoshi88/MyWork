//Accept N numbers from user and return product of all odd elements.
//Input : N : 6
//Elements : 15 66 3 70 10 88
//Output : 45
//Input : N : 6
//Elements : 44 66 72 70 10 88
//Output : 0
#include <stdio.h>
#include <stdlib.h>
int Product(int Arr[],int iLength)
{
    int i=0;
    int iProd=1;
    int oddPresent=0;
    for(i=iLength-1;i>=0;i--)
    {
        if(Arr[i]%2!=0)
        {
            oddPresent=1;
            iProd=iProd*Arr[i];
        }
    }
    if(oddPresent==1)
    {
        return iProd;
    }
    else
    {
        return 0;
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

    iRet=Product(p,iSize);
    printf("Product is %d",iRet);
    
    free(p);
    return 0;
}
