//Write application which accept two file names from user. Compare the contents of
//that two files. If contents are same then return true otherwise return false.
//Input : Demo.txt Hello.txt
//Output : Compare contents of Demo.txt and Hello.txt

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
    char f1[30];
    char f2[30];
    void Accept()
    {
        cout<<"Enter the first file name:";
        cin>>f1;
        cout<<"Enter the second file name:";
        cin>>f2;
    }
    void OpenFiles()
    {
        fd1 = open(f1,O_RDONLY);
        if(fd1==-1)
        {
            cout<<"Unable to open the file";
        }
        fd2 = open(f2,O_RDONLY);
        if(fd2==-1)
        {
            cout<<"Unable to open the file";
        }
    }
    int GetContent(int fd)
    {
        int iCount=0;
        char Arr[10];
        int ret=0;
        while((ret=read(fd,Arr,10))!=0)
        {
            //write(1,Arr,ret);
            iCount=iCount+ret;
        }
        return iCount;

    }
    bool CompareData()
    {
        char ch1[1];
        char ch2[1];
        int ret1;
        int ret2;
        int isSame=0;
        if(GetContent(fd1) !=GetContent(fd2))
        {
            return false;
        }
        close(fd1);
        close(fd2);
        OpenFiles();
        while(((ret1=read(fd1,ch1,1))!=0) && ((ret2=read(fd2,ch2,1))!=0))
        {
            if(ch1[0]!=ch2[0])
            {
                isSame=1;
                break;
            }
        }
        if(isSame==1)
        {
            return false;
        }
        else
        {
            return true;
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
    bool bRet=false;
    FileX obj;
    obj.Accept();
    obj.OpenFiles();
    bRet=obj.CompareData();
    if(bRet==true)
    {
        cout<<"True\n";
    }
    else
    {
        cout<<"False\n";
    }
    return 0;
}