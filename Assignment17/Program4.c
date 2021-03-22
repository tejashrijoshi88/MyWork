//Accept N numbers from user and display all such elements which are
//divisible by 3 and 5.
//Input : N : 6
//Elements : 85 66 3 15 93 88
//Output : 15
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
        if(Arr[i]%3==0 && Arr[i]%5==0)
        {
            printf("%d",Arr[i]);
        }
    }
}
int main()
{
    int iSize=0;
    int iCnt=0;
    int *p=NULL;
    printf("Enter the Number of elements: ");
    scanf("%d",&iSize);
    p= (int*)malloc(iSize*sizeof(int));
    if(p==NULL)
    {
        printf("Unable to allocate memory");
        return -1;
    }
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("Enter Element: %d :",iCnt);
        scanf("%d",&p[iCnt]);
    }
    Display(p,iSize);
    free(p);
    return 0;
}
