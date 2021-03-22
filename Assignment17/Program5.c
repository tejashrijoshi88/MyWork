//Accept N numbers from user and display all such elements which are
//multiples of 11.
//Input : N : 6
//Elements : 85 66 3 55 93 88
//Output : 66 55 88
#include <stdio.h>
#include <stdlib.h>
void Display(int Arr[],int iLength)
{
    if(Arr==NULL || iLength==0)
    {
        return;
    }
    for(int i=0;i<iLength;i++)
    {
        if(Arr[i]%11==0)
        {
            printf("%d ",Arr[i]);
        }
    }
}
int main()
{
    int iSize=0;
    int iCnt=0;
    int *p=NULL;
    printf("Enter the Number of Elements: ");
    scanf("%d",&iSize);
    p=(int*)malloc(iSize*sizeof(int));
    if(p==NULL)
    {
        printf("unable to assign memory");
        return -1;
    }
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("Enter the Element: %d :",iCnt);
        scanf("%d",&p[iCnt]);
    }
    Display(p,iSize);
    return 0;
}
