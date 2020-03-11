
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


class Dictionary
{
    public:
        Dictionary();
        ~Dictionary();
        
        void ReadFileList(string FileName);
        void ReadFileBook(string FileName);
        int Binary_Search(string words, int low, int high);
        double Search();
        
    private:
        static const int SIZE = 1000;
        int Count;
        int ArrayRank[SIZE];
        string ArrayWords[SIZE];
        string ArrayBook[SIZE];
        
};