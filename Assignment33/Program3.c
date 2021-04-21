//Write a program which returns addition of all element from singly linear
//linked list.
//Function Prototype :
//int Addition( PNODE Head);
//Input linked list : |10|->|20|->|30|->|40|
//Output : 100
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
int Addition(PNODE Head)
{
    int iSum=0;

    while (Head!=NULL)
    {
        iSum=iSum+Head->data;
        Head=Head->next;
    }
    return iSum;
} 
int main()
{
    PNODE first=NULL;
    int LastOcc=0;
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);

    Display(first);
    LastOcc=Addition(first);
    printf("%d\n",LastOcc);
    return 0;
}