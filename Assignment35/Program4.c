//Write a program which display smallest digits of all element from singly
//linear linked list.
//Function Prototype :
//void DisplaySmall( PNODE Head);
//Input linked list : |11|->|250|->|532|->|415|
//Output : 1 0 2 1
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
int getSmallestDigit(int iNo)
{
    int iSmall=9;
    int iDigit=0;
    while(iNo>0)
    {
        iDigit=iNo%10;
        if(iDigit<iSmall)
        {
            iSmall=iDigit;
        }
        iNo=iNo/10;
    }
    return iSmall;
}
void DisplaySmall(PNODE Head)
{  
    int iSmall=0;  
    while (Head!=NULL)
    {
        iSmall=getSmallestDigit(Head->data);
        printf("%d\t",iSmall);
        Head=Head->next;
    }
} 
int main()
{
    PNODE first=NULL;
    InsertFirst(&first,415);
    InsertFirst(&first,532);
    InsertFirst(&first,250);
    InsertFirst(&first,11);
    DisplaySmall(first);
    return 0;
}