//Write a program which returns addition of all even element from singly
//linear linked list.
//Function Prototype :
//int AdditionEven( PNODE Head);
//Input linked list : |11|->|20|->|32|->|41|
//Output : 52
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node * next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
void InsertFirst(PPNODE Head,int no)
{
    PNODE newNode=NULL;
    newNode=(PNODE)malloc(sizeof(PNODE));
    newNode->data=no;
    newNode->next=NULL;
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

int AdditionEven(PNODE Head)
{
    int iSumEven=0;
    while (Head!=NULL)
    {
        if((Head->data)%2==0)
        {
            iSumEven=iSumEven+Head->data;
        }
        Head=Head->next;
    }
    return iSumEven;
} 
int main()
{
    PNODE first=NULL;
    int iSumEven=0;

    InsertFirst(&first,41);
    InsertFirst(&first,32);
    InsertFirst(&first,20);
    InsertFirst(&first,11);
    iSumEven=AdditionEven(first);
    printf("%d\n",iSumEven);
    return 0;
}