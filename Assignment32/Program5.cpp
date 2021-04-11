//Accept three file names from user which are existing files. Create one new file
//named as Demo.txt. Write name and Data of that three files in Demo.txt file one
//after another.
//Input : abc.txt
//pqr.txt
//xyz.txt
//Output : Write file name and data of each file in Demo.txt file.
//Piyush

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
    int fd3;
    int fd4;
    char f1[30];
    char f2[30];
    char f3[30];
    char f4[30]="Demo.txt";
    void Accept()
    {
        cout<<"Enter the first file name:";
        cin>>f1;
        cout<<"Enter the second file name:";
        cin>>f2;
        cout<<"Enter the third file name:";
        cin>>f3;

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
        fd3 = open(f3,O_RDONLY);
        if(fd3==-1)
        {
            cout<<"Unable to open the file";
        }
        fd4 = open(f4,O_WRONLY | O_CREAT |O_APPEND);
        if(fd4==-1)
        {
            cout<<"Unable to open the file";
        }
    }
    int StringLenX(char str[])
    {
        int iCount=0;
        for(int i=0;str[i]!='\0';i++)
        {
            iCount++;
        }
        return iCount;
    }
    void CopyData()
    {
        char ch1[10];
        char ch2[1];
        int ret1;
        int ret2;
        int isSame=0;
        write(fd4,f1,StringLenX(f1));
        write(fd4,"\n",1);
        while((ret1=read(fd1,ch1,10))!=0)
        {
            write(fd4,ch1,ret1);
        }
        write(fd4,"\n",1);
        write(fd4,f2,StringLenX(f2));
        write(fd4,"\n",1);
        while((ret1=read(fd2,ch1,10))!=0)
        {
            write(fd4,ch1,ret1);
        }  
        write(fd4,"\n",1); 
        write(fd4,f3,StringLenX(f3));
        write(fd4,"\n",1);
        while((ret1=read(fd3,ch1,10))!=0)
        {
            write(fd4,ch1,ret1);
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
    obj.CopyData();
    return 0;
}