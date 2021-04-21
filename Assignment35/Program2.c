//Write a program which display all palindrome elements of singly linked
//list.
//Function Prototype :
//void DisplayPallindrome( PNODE Head);
//Input linked list : |11|->|28|->|17|->|414|->|6|->|89|
//Output : 11 6 414
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
bool isPalindrome(int iNo)
{
    int iVal=iNo;
    int iReverse=0;
    int iDigit=0;
    while(iNo>0)
    {
        iDigit=iNo%10;
        iReverse=(iReverse*10)+iDigit;
        iNo=iNo/10;
    }
    if(iVal==iReverse)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DisplayAllPalindrom(PNODE Head)
{  
    int iReverse=0;  
    while (Head!=NULL)
    {
        if(isPalindrome(Head->data))
        {
            printf("%d\t",Head->data);
        }
        Head=Head->next;
    }
} 
int main()
{
    PNODE first=NULL;
    int iSecMax=0;

    InsertFirst(&first,89);
    InsertFirst(&first,6);
    InsertFirst(&first,414);
    InsertFirst(&first,17);
    InsertFirst(&first,28);
    InsertFirst(&first,11);
    DisplayAllPalindrom(first);
    return 0;
}