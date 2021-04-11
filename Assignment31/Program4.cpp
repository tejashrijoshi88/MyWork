//Write application which accept file name from user and display size of file.
//Input : Demo.txt
//Output : File size is 56 bytes
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
            cout<<"File sucessfully opened\n";
        }
    }
    void ReadData()
    {
        char Arr[10];
        int ret=0;
        int count=0;
        while((ret=read(fd,Arr,10))!=0)
        {
            //write(1,Arr,ret);
            count=count+ret;
        }
        cout<<"File Size is "<<count<<" bytes \n";

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