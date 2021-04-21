//Write a program which displays all elements which are perfect from singly
//linear linked list.
//Function Prototype :
//int DisplayPerfect( PNODE Head);
//Input linked list : |11|->|28|->|17|->|41|->|6|->|89|
//Output : 6 28
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node * next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
void InsertFirst(PPNODE Head,int No)
{
    PNODE newNode=NULL;
    newNode=(PNODE)malloc(sizeof(PNODE));
    newNode->next=NULL;
    newNode->data=No;
    if(*Head==NULL)
    {
        *Head=newNode;
    }
    else
    {
        newNode->next=*Head;
        *Head=newNode;
    }
}
void Display(PNODE Head)
{
    while(Head!=NULL)
    {
        printf("%d\n",Head->data);
        Head=Head->next;
    }
}
bool isPerfect(int iNo)
{
    int iSum=0;
    for(int i=1;i<=iNo/2;i++)
    {
        if(iNo%i==0)
        {
            iSum=iSum+i;
        }
    }
    if(iSum==iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DisplayPerfect(PNODE Head)
{

    while(Head!=NULL)
    {
        if(isPerfect(Head->data))
        {
            printf("%d\n",Head->data);
        }
        Head=Head->next;
    }
    
}
int main()
{
    PNODE first=NULL;
    int ElementOcc=0;
    InsertFirst(&first,89);
    InsertFirst(&first,6);
    InsertFirst(&first,41);
    InsertFirst(&first,17);
    InsertFirst(&first,28);
    InsertFirst(&first,11);
    InsertFirst(&first,10);
    DisplayPerfect(first);
    return 0;
}
