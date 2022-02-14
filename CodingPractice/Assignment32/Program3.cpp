//Write application which accept two file names from user. Append the contents of
//first file at the end of second file.
//Input : Demo.txt Hello.txt
//Output : Concat contents of Demo.txt at the end of Hello.txt

#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
using namespace std;

class FileX
{
public:
    int fd1;
    int fd2;

    FileX(char Name1[],char Name2[])
    {
        fd1 = open(Name1,O_RDONLY);
        if(fd1==-1)
        {
            cout<<"Unable to open the file";
        }
        fd2 = open(Name2,O_WRONLY|O_APPEND);
        if(fd2==-1)
        {
            cout<<"Unable to open the file";
        }
    }

    void CopyData()
    {
        char ch1[10];
        int ret1;
        while((ret1=read(fd1,ch1,10))!=0)
        {
            write(fd2,ch1,ret1);
        }

    }
    ~FileX()
    {
        close(fd1);
        close(fd2);
    }
};
int main()
{
    char str1[30];
    char str2[30];
    cout<<"Enter the first file name:";
    cin>>str1;
    cout<<"Enter the second file name:";
    cin>>str2;
    FileX obj(str1,str2);
    obj.CopyData();
    return 0;
}