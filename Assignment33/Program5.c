//Write a program which return smallest element from singly linear linked
//list.
//Function Prototype :
//int Minimum( PNODE Head);
//Input linked list : |110|->|230|->|20|->|240|->|640|
//Output : 20
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
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
int Minimum(PNODE Head)
{
    int iMin=Head->data;
    while(Head!=NULL)
    {
        if(Head->data <iMin)
        {
            iMin=Head->data;
        }
        Head=Head->next;
    }
    return iMin;
}
int main()
{
    PNODE first=NULL;
    int Min=0;
    InsertFirst(&first,640);
    InsertFirst(&first,240);
    InsertFirst(&first,20);
    InsertFirst(&first,230);
    InsertFirst(&first,110);
    Min=Minimum(first);
    printf("%d\n",Min);
    return 0;
}