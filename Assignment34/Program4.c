//Write a program which return second maximum element from singly linear
//linked list.
//Function Prototype :
//int SecMaximum( PNODE Head);
//Input linked list : |110|->|230|->|320|->|240|
//Output : 240
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

int SecMaximum(PNODE Head)
{
    int iMax=Head->data;
    int iSecMax=(Head->next)->data;
    
    while (Head!=NULL)
    {
        if(iMax<Head->data)
        {
            iSecMax=iMax;
            iMax=Head->data;
        }
        else if(iSecMax<Head->data && Head->data<iMax)
        {
            iSecMax=Head->data;
        }
        Head=Head->next;
    }
    return iSecMax;
} 
int main()
{
    PNODE first=NULL;
    int iSecMax=0;

    InsertFirst(&first,240);
    InsertFirst(&first,320);
    InsertFirst(&first,230);
    InsertFirst(&first,110);
    
    iSecMax=SecMaximum(first);
    printf("%d\n",iSecMax);
    return 0;
}