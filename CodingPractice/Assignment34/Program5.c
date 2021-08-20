//Write a program which display addition of digits of element from singly
//linear linked list.
//Function Prototype :int SumDigit( PNODE Head);
//Input linked list : |110|->|230|->|20|->|240|->|640|
//Output : 2 5 2 6 10
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
int getSumDigit(int iNo)
{
    int iSum=0;
    int iDigit=0;
    while(iNo>0)
    {
        iDigit=iNo%10;
        iSum=iSum+iDigit;
        iNo=iNo/10;
    }
    return iSum;
}
void SumDigit(PNODE Head)
{  
    int iSum=0;  
    while (Head!=NULL)
    {
        iSum=getSumDigit(Head->data);
        printf("%d\t",iSum);
        Head=Head->next;
    }
    return iSum;
} 
int main()
{
    PNODE first=NULL;
    int iSecMax=0;

    InsertFirst(&first,640);
    InsertFirst(&first,240);
    InsertFirst(&first,20);
    InsertFirst(&first,230);
    InsertFirst(&first,110);
    SumDigit(first);
    return 0;
}