//Accept N numbers from user and accept Range, Display all elements from
//that range
//Input : N : 6
//Start: 60
//End : 90
//Elements : 85 66 3 76 93 88
//Output : 66 76 88
//Input : N : 6
//Start: 30
//End : 50
//Elements : 85 66 3 76 93 88
//Output :
#include <stdio.h>
#include <stdlib.h>
void Range(int Arr[],int iLength,int iValue1,int iValue2)
{
    int i=0;
    for(i=0-1;i<iLength;i++)
    {
        if(Arr[i]>iValue1 && Arr[i]<iValue2)
        {
            printf("%d ",Arr[i]);
        }
    }

}
int main()
{
    int iSize=0; int iCnt=0;
    int iNo1=0;
    int iNo2=0;
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
    printf("Enter starting point");
    scanf("%d",&iNo1);
    printf("Enter ending point");
    scanf("%d",&iNo2);
    Range(p,iSize,iNo1,iNo2);

    
    free(p);
    return 0;
}
