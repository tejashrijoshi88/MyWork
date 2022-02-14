//Write application which accept file name from user and one string from user. Write
//that string at the end of file.
//Input : Demo.txt
//Hello World
//Output : Write Hello World at the end of Demo.txt file
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
    char str[20];
    FileX(char Name[])
    {
        fd = open(Name,O_WRONLY|O_APPEND);
        if(fd==-1)
        {
            cout<<"Unable to open the file";
        }
        else
        {
            cout<<"File sucessfully opened\n";
        }
    }
    void Accept()
    {
        cout<<"Enter the string to append \n";  
        scanf(" %[^'\n']s",str);     
    }
    int StringLenX()
    {
        int iCount=0;
        for(int i=0;str[i]!='\0';i++)
        {
            iCount++;
        }
        return iCount;
    }
    void WriteData()
    {
        int iCount=StringLenX();
        write(fd,str,iCount);
    }
    ~FileX()
    {
        close(fd);
    }
};
int main()
{
    char str[30];
    cout<<"Enter the file name:";
    cin>>str;
    FileX obj(str);
    obj.Accept();
    obj.WriteData();
    return 0;
}