//Write a program which reverse each element of singly linked list.
//Function Prototype :
//void Reverse( PNODE Head);
//Input linked list : |11|->|28|->|17|->|41|->|6|->|89|
//Output : |11|->|82|->|71|->|14|->|6|->|98|
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
int getReverse(int iNo)
{
    int iReverse=0;
    int iDigit=0;
    while(iNo>0)
    {
        iDigit=iNo%10;
        iReverse=(iReverse*10)+iDigit;
        iNo=iNo/10;
    }
    return iReverse;
}
void Reverse(PNODE Head)
{  
    int iReverse=0;  
    while (Head!=NULL)
    {
        iReverse=getReverse(Head->data);
        printf("%d\t",iReverse);
        Head=Head->next;
    }
} 
int main()
{
    PNODE first=NULL;
    int iSecMax=0;

    InsertFirst(&first,89);
    InsertFirst(&first,6);
    InsertFirst(&first,41);
    InsertFirst(&first,17);
    InsertFirst(&first,28);
    InsertFirst(&first,11);
    Reverse(first);
    return 0;
}