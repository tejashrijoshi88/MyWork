// Program to print 5 to 1 numbers on screen
// input = none
// output = none

#include <stdio.h>
void Display()
{
    int i=0;

    for(i=5;i>=1;i--)
    {
        printf("%d\n",i);
    }
}
int main()
{
    Display();
    return 0;
}