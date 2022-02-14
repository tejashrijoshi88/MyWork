// Accept one character from user and check if that character is vowel or not 
// input = char
// output = bool (true if it is vowel else false)

#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
bool ChkVowel(char cChar)
{
    if(cChar == 'A' || cChar == 'E' || cChar =='I' || cChar=='O' || cChar=='U'||
       cChar == 'a' || cChar == 'e' || cChar =='i' || cChar=='o' || cChar=='u')
    {
        return true;
    } 
    else
    {
        return false;
    }

}
int main()
{
    char cVal='\0';
    bool bRet=false;
    printf("Enter characerer ");
    scanf("%c",&cVal);
    
    bRet = ChkVowel(cVal);
    if(bRet == true)
    {
        printf("It is vowel");
    }
    else
    {
        printf("It is not vowel");
    }
    return 0;
}