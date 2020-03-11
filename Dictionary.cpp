
#include "Dictionary.h"


Dictionary::Dictionary()
{
    Count = 0;
    ArrayRank[SIZE];
    ArrayWords[SIZE];
    ArrayBook[SIZE];
}

Dictionary::~Dictionary()
{
    
}

void Dictionary::ReadFileList(string FileName)
{
    // Open input file
    ifstream din;
    din.open(FileName.c_str());
    if (din.fail())
        return;
        
    string Temp[2000];
    while (!din.eof())
    {
        for(int i = 0; i < 2000; i++)
        {
            din >> Temp[i];
        }
    }
    din.close();

    int j = 0;
    int k = 0;
    for(int i = 0; i < 2000; i++)
    {
        if (i % 2 == 0)
        {
            ArrayRank[j] = stoi(Temp[i]);
            j++;
        }
        else if (i % 2 == 1)
        {
            ArrayWords[k] = Temp[i];
            k++;
        }
    }
    
    //Prints for testing
    /*for(int i = 0; i < 1000; i++)
    {
        cout << ArrayRank[i] << endl;
    }*/
    
}

void Dictionary::ReadFileBook(string FileName)
{
    // Open input file
    ifstream din;
    din.open(FileName.c_str());
    if (din.fail())
        return;
        
    while (!din.eof())
    {
        for(int i = 0; i < SIZE; i++)
        {
            din >> ArrayBook[i];
            string temp = ArrayBook[i];
            for (int j = 0; j < temp.size(); j++)
            {
                if (((temp[j] == '.') || (temp[j] == '?') || (temp[j] == '\'') || 
                    (temp[j] == ')') || (temp[j] == '(') || (temp[j] == ',') || 
                    (temp[j] == '-') || (temp[j] == '!') || (temp[j] == '\"') ||
                    (temp[j] == '_') || (temp[j] == ';') || (temp[j] == ':')) && (j == 0 || j == (temp.size()-1)))
                {
                    temp.erase(temp.begin() + j);
                }
                else
                    temp[j] = tolower(temp[j]);
            }
            ArrayBook[i] = temp;
            if(ArrayBook[i] != "")
                Count++;
        }
        
    }
    din.close();
    
    //Prints for testing
    /*for(int i = 0; i < count; i++)
    {
        cout << ArrayBook[i] << endl;
    }*/
    
}

int Dictionary::Binary_Search(string word, int low, int high)
{
    // Calculate midpoint index
    int mid = (low+high)/2;

    // Check termination condition
    if (ArrayWords[low] > ArrayWords[high])
        return 1001;

    // Check if value is found
    else if (ArrayWords[mid] == word)
        return ArrayRank[mid];

    // Search to the left
    else if (ArrayWords[mid] > word)
        return Binary_Search(word, low, mid - 1);

    // Search to the right
    else 
        return Binary_Search(word, mid + 1, high);
}

double Dictionary::Search()
{
    int low = 0;
    int high = 999;
    double levelcount = 0;
    int x = 0;
    
    //Start by using each word in ArrayBook
    for (int i = 0; i < Count; i++)
    {
        //Binary search for that word's rank and add it to levelcount
        string word = ArrayBook[i];
        x = Binary_Search(word,low,high);
        levelcount = levelcount + x;
    }
    
    double average = levelcount / Count;
    return average;
}




