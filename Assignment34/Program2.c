//Write a program which displays all elements which are prime from singly
//linear linked list.
//Function Prototype :
//int DisplayPrime( PNODE Head);
//Input linked list : |11|->|20|->|17|->|41|->|22|->|89|
//Output : 11 17 41 89
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
bool isPrime(int iNo)
{
    int i=0;
    for(i=2;i<iNo/2;i++)
    {
        if(iNo%i==0)
        {
            break;
        }
    }
    if(i==(iNo/2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DisplayPrime(PNODE Head)
{
    while (Head!=NULL)
    {
        if(isPrime(Head->data))
        {
            printf("%d\n",Head->data);
        } 
        Head=Head->next;
    }
   
} 
int main()
{
    PNODE first=NULL;
    int LastOcc=0;
    InsertFirst(&first,89);
    InsertFirst(&first,6);
    InsertFirst(&first,41);
    InsertFirst(&first,17);
    InsertFirst(&first,20);
    InsertFirst(&first,11);
    InsertFirst(&first,10);
    DisplayPrime(first);
    return 0;
}