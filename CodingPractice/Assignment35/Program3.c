//Write a program which display product of all digits of all element from
//singly linear linked list. (Don’t consider 0)
//Function Prototype :
//void DisplayProduct( PNODE Head);
//Input linked list : |11|->|20|->|32|->|41|
//Output : 1 2 6 4
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
int getDigitProduct(int iNo)
{
    int iProduct=1;
    int iDigit=0;
    while(iNo>0)
    {
        iDigit=iNo%10;
        if(iDigit!=0)
        {
            iProduct=iProduct*iDigit;
        }
        iNo=iNo/10;
    }
    return iProduct;
}
void DisplayProduct(PNODE Head)
{  
    int iProduct=0;  
    while (Head!=NULL)
    {
        iProduct=getDigitProduct(Head->data);
        printf("%d\t",iProduct);
        Head=Head->next;
    }
} 
int main()
{
    PNODE first=NULL;
    InsertFirst(&first,41);
    InsertFirst(&first,32);
    InsertFirst(&first,20);
    InsertFirst(&first,11);
    DisplayProduct(first);
    return 0;
}