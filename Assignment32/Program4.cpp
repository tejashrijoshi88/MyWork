/*
Write application which accept file name and one word from user. Count the 
frequency of that word in file. 
Input : Marvellous.txt 
 Hello 
Output : Count the frequency if Hello in Marvellous.txt file. 
*/
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
using namespace std;
class FileX
{
public:
    int fd, occurences = 0, filelength = 0;
    char Name[30];
    void OpenFiles()
    {
        fd = open(Name, O_RDONLY);
        if (fd == -1)
        {
            cout << "Unable to open file\n";
            exit(0);
        }
        else
        {
            cout << "File succesfully opened..\n";
        }
    }
    void Accept()
    {
        cout << "Enter file name\n";
        scanf(" %[^'\n']s", Name);
    }
    int StrlenX(char strSearch[])
    {
        int iCnt = 0;
        char *ptr = strSearch;
        while (*ptr != '\0')
        {
            ptr++;
            iCnt++;
        }
        return iCnt;
    }
    int GetContentLengthOfFiles()
    {
        char Arr[20];
        int ret = 0;
        while ((ret = read(fd, Arr, 10)) != 0)
        {
            filelength = filelength + ret;
        }
        close(fd);
        return filelength;
    }
    bool CompareStrings(char Arr[], char strSearch[])
    {
        bool compare = false;
        if (StrlenX(Arr) != StrlenX(strSearch))
        {
            return compare;
        }
        else
        {
            for (int i = 0; i < StrlenX(strSearch); i++)
            {
                if (Arr[i] != strSearch[i])
                {
                    compare = false;
                    break;
                }
                else
                {
                    compare = true;
                }
            }
        }
        return compare;
    }
    int FindOccurrences(char strSearch[])
    {
        char Arr[1];
        char *WordInFile = NULL;
        int filelength = GetContentLengthOfFiles();
        OpenFiles();
        char str[filelength];
        int ret = 0, iCnt1 = 0;
        while ((ret = read(fd, Arr, 1)) != 0)
        {
            str[iCnt1] = Arr[0];
            iCnt1++;
        }
        char *ptr = str;
        while (*ptr != '\0')
        {
            WordInFile = new char[StrlenX(strSearch)];
            if (*ptr == ' ')
            {
                while ((*ptr == ' ') && (*ptr != '\0'))
                {
                    ptr++;
                }
            }
            else if (*ptr == '\n')
            {
                while ((*ptr == '\n') && (*ptr != '\0'))
                {
                    ptr++;
                }
            }
            else
            {
                int iCnt = 0;
                while ((*ptr != ' ') && (*ptr != '\0'))
                {
                    if (iCnt >= StrlenX(strSearch))
                    {
                        break;
                    }
                    WordInFile[iCnt] = *ptr;
                    ptr++;
                    iCnt++;
                }
                WordInFile[iCnt] = '\0';
                if (CompareStrings(WordInFile, strSearch) == true)
                {
                    occurences++;
                }
            }
        }
        return occurences;
    }
    ~FileX()
    {
        close(fd);
    }
};
int main()
{
    char str[30];
    char strSearch[30];
    int iRet = 0;
    FileX obj;
    obj.Accept();
    cout << "Enter string to search\n";
    cin >> strSearch;
    obj.OpenFiles();
    iRet = obj.FindOccurrences(strSearch);
    cout << "No of Occurrences for string - " << strSearch << " in the file = " << iRet;
    return 0;
}