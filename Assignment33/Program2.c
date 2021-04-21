//Write a program which search last occurrence of particular element from
//singly linear linked list.
//Function should return position at which element is found.
//Function Prototype :
//int SearchLastOcc( PNODE Head, int no );
//Input linked list : |10|->|20|->|30|->|40|->|50|->|30|->|70|
//Input element : 30
//Output : 6
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
int SearchLastOcc(PNODE Head,int no)
{
    int iCnt=0;
    int LastOcc=-1;
    while (Head!=NULL)
    {
        iCnt++;
        if(Head->data==no)
        {
            LastOcc=iCnt;
        } 
        Head=Head->next;
    }
    return LastOcc;
} 
int main()
{
    PNODE first=NULL;
    int LastOcc=0;
    InsertFirst(&first,70);
    InsertFirst(&first,30);
    InsertFirst(&first,50);
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);
    Display(first);
    LastOcc=SearchLastOcc(first,30);
    printf("%d\n",LastOcc);
    return 0;
}