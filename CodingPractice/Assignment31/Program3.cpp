//Write application which accept file name from user and read all data from that file
//and display contents on screen.
//Input : Demo.txt
//Output : Display all data of file.
//Write application which accept file name from user and open that file in read mode.
//Input : Demo.txt
//Output : File opened successfully.
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
    FileX(char Name[])
    {
        fd = open(Name,O_RDONLY);
        if(fd==-1)
        {
            cout<<"Unable to open the file";
        }
        else
        {
            cout<<"File sucessfully opened";
        }
    }
    void ReadData()
    {
        char Arr[10];
        int ret=0;
        while((ret=read(fd,Arr,10))!=0)
        {
            write(1,Arr,ret);
           
        }
        

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
    obj.ReadData();
    return 0;
}