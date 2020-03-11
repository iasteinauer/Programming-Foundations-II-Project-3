
#include "Dictionary.h"

int main()
{  
    string filename;
    
    cout << "Welcome to Project 3, reading level check." << endl;
    
    Dictionary call1;
    call1.ReadFileList("words.txt");
    cout << "Enter book sample text file: ";
    cin >> filename;
    call1.ReadFileBook(filename);
    double average1 = call1.Search();
    cout << "The average reading level of this file is: " << average1 << endl << endl;
    
    Dictionary call2; 
    call2.ReadFileList("words.txt");
    cout << "Enter book sample text file: ";
    cin >> filename;
    call2.ReadFileBook(filename);
    double average2 = call2.Search();
    cout << "The average reading level of this file is: " << average2 << endl << endl;
    
    Dictionary call3;
    call3.ReadFileList("words.txt");
    cout << "Enter book sample text file: ";
    cin >> filename;
    call3.ReadFileBook(filename);
    double average3 = call3.Search();
    cout << "The average reading level of this file is: " << average3 << endl << endl;
    
    Dictionary call4;
    call4.ReadFileList("words.txt");
    cout << "Enter book sample text file: ";
    cin >> filename;
    call4.ReadFileBook(filename);
    double average4 = call4.Search();
    cout << "The average reading level of this file is: " << average4 << endl << endl;
    
    Dictionary call5;
    call5.ReadFileList("words.txt");
    cout << "Enter book sample text file: ";
    cin >> filename;
    call5.ReadFileBook(filename);
    double average5 = call5.Search();
    cout << "The average reading level of this file is: " << average5 << endl << endl;
    
    
}
