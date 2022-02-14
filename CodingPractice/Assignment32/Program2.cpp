//Write application which accept file name and one character from user. Count the
//frequency of that character in file.
//Input : Demo.txt
//M
//Output : Count occurrence of M in Demo.txt
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
using namespace std;

class FileX
{
public:
    int fd;
    char ch;
    FileX(char Name[])
    {
        fd =open(Name,O_RDONLY);
        if(fd==-1)
        {
            cout<<"Unable to open the file";
        }
    }
    void Accept()
    {
        cout<<"Enter the character :\n";
        cin>>ch;
    }
    int CharFrequency()
    {
        int ret;
        int iCount=0;
        char Arr[1];
        while(((ret=read(fd,Arr,1))!=0))
        {
            if(Arr[0]==ch)
            {
                iCount++;
            }
        }
        return iCount;
    }
    ~FileX()
    {
        close(fd);
    }
};
int main()
{
    char str[30];
    int iRet=0;
    cout<<"Enter the file name:";
    cin>>str;
    FileX obj(str);
    obj.Accept();
    iRet=obj.CharFrequency();
    cout<<"Frequency is: "<<iRet<<"\n"; 
    return 0;
}