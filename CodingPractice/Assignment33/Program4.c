//Write a program which return largest element from singly linear linked
//list.
//Function Prototype :
//int Maximum( PNODE Head);
//Input linked list : |110|->|230|->|320|->|240|
//Output : 320
#include<stdio.h>
#include<stdlib.h>
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
int Maximum(PNODE Head)
{
    int iMax=Head->data;

    while (Head!=NULL)
    {
        if(iMax<Head->data)
        {
            iMax=Head->data;
        }
        Head=Head->next;
    }
    return iMax;
} 
int main()
{
    PNODE first=NULL;
    int LastOcc=0;
    InsertFirst(&first,240);
    InsertFirst(&first,320);
    InsertFirst(&first,230);
    InsertFirst(&first,110);

    Display(first);
    LastOcc=Maximum(first);
    printf("%d\n",LastOcc);
    return 0;
}