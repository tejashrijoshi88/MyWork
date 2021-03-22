// Accept number from user and display given pattern
// input = 4 4
// output - # 
        //  # # 
        //  # # # 
        //  # # # #


/////////////////////////////////////////////////////////////////////
// Function Name - Display
// input - integer
// output - Pattern
// Desc - Displays specific given pattern
// Date - 10/03/2021
// Author - Tejashri Joshi
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
void Display(unsigned int iRow,unsigned int iCol)
{ 
    char ch='\0';
    if(iRow!=iCol)
    {
        return;
    }
    for(int i=1, ch='A';i<=iRow;i++,ch++)
    {
        for(int j=1;j<=iCol;j++)
        { 
            if(i>=j)
            {
                printf("%c\t",ch);      
            }     
        }    
        printf("\n");
    }
}
int main()
{
    unsigned int iVal1=0;
    unsigned int iVal2=0;
    printf("Enter Number of rows ");
    scanf("%u",&iVal1);
    printf("Enter Number of cols ");
    scanf("%u",&iVal2);

    Display(iVal1,iVal2);
    return 0;
}