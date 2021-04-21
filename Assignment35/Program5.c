//Write a program which display largest digits of all element from singly
//linear linked list.
//Function Prototype :
//void DisplayLarge( PNODE Head);
//Input linked list : |11|->|250|->|532|->|419|
//Output : 1 5 5 9
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
int getLargestDigit(int iNo)
{
    int iLarge=0;
    int iDigit=0;
    while(iNo>0)
    {
        iDigit=iNo%10;
        if(iDigit>iLarge)
        {
            iLarge=iDigit;
        }
        iNo=iNo/10;
    }
    return iLarge;
}
void DisplayLarge(PNODE Head)
{  
    int iLarge=0;  
    while (Head!=NULL)
    {
        iLarge=getLargestDigit(Head->data);
        printf("%d\t",iLarge);
        Head=Head->next;
    }
} 
int main()
{
    PNODE first=NULL;
    InsertFirst(&first,419);
    InsertFirst(&first,532);
    InsertFirst(&first,250);
    InsertFirst(&first,11);
    DisplayLarge(first);
    return 0;
}