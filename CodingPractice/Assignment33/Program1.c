//Write a program which search first occurrence of particular element from
//ingly linear linked list.
//Function should return position at which element is found.
//Function Prototype :
//int SearchFirstOcc( PNODE Head , int no );
//Input linked list : |10|->|20|->|30|->|40|->|50|->|30|->|70|
//Input element : 30
//Output : 3
#include<stdio.h>
#include<stdlib.h>
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
int SearchFirstOcc(PNODE Head,int No)
{
    int iCnt=0;
    int elementNumber=-1;
    while(Head!=NULL)
    {
        iCnt++;
        if(Head->data==No)
        {
            elementNumber=iCnt;
            break;
        }
        Head=Head->next;
    }
    return elementNumber;
}
int main()
{
    PNODE first=NULL;
    int ElementOcc=0;
    InsertFirst(&first,70);
    InsertFirst(&first,30);
    InsertFirst(&first,50);
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);
    Display(first);
    ElementOcc=SearchFirstOcc(first,30);
    printf("%d\n",ElementOcc);
    return 0;
}
