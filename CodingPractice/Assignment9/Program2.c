// Write a program which accept range from user and display all even numbers in between that range.
//Input : 23 35
//Output : 24 26 28 30 32 34
//Input : 10 18
//Output : 10 12 14 16 18
//Input : 10 10
// Output : 10
// Input : -10 2
// Output : -10 -8 -6 -4 -2 0 2
// time complexity O(n/2) where n=difference between two numbers
#include <stdio.h>


void RangeDisplayEven(int iNo1,int iNo2)
{
  if(iNo1>iNo2)
  {
      printf("Invalid range");
  }
  int i =0;
  if(iNo1%2==0)
  {
      i=iNo1;
  }
  else{i=iNo1+1;}
  for(;i<=iNo2;i=i+2)
  {
      printf("%d ",i);
  }
}
int main()
{
    int iVal1;
    int iVal2;
    printf("Enter first Number ");
    scanf("%d",&iVal1);
    printf("Enter second Number ");
    scanf("%d",&iVal2);
    RangeDisplayEven(iVal1,iVal2);
    return 0;
}