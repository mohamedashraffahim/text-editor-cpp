//files 2

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

fstream my_file;
string file_name;



void open_file()
{
    cout << "Enter name of file you want to open ex: file called \"test\" in folder: ";
    getline(cin, file_name);
    my_file.open(file_name, ios::in);
    while (my_file.fail())
    {
        cout << file_name << " is not a file name, try again!";
        cin.clear();
        cin.sync();
        getline(cin, file_name);
        my_file.open(file_name, ios::in);
    }

}

void repeated_word()
{

    string text, word;
    int count = 0;
    open_file();

    if (my_file.is_open())
    {
        cout << "Enter the word: ";
        cin >> word;
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }

        while (my_file >> text)
        {
            for (int i = 0; i < text.length(); i++)
            {
                text[i] = tolower(text[i]);
            }

            if (text == word || text == word + '.')
                count++;
        }

        my_file.close();
        cout << count << endl;
    }
}

void upper_words()
{

    string line, upper_words;
    open_file();

    if (my_file.is_open())
    {
        while (getline(my_file, line))
        {
            upper_words += line;
            upper_words += "\n";
        }
        my_file.close();
    }

    for (int i = 0; i < upper_words.length(); i++)
    {
        upper_words[i] = toupper(upper_words[i]);
    }

    my_file.open(file_name, ios::out);
    if (my_file.is_open()) {
        my_file << upper_words;
        my_file.close();
    }
}

void lower_words()
{

    string line, lower_words;
    open_file();

    if (my_file.is_open())
    {
        while (getline(my_file, line))
        {
            lower_words += line;
            lower_words += "\n";
        }
        my_file.close();
    }

    for (int i = 0; i < lower_words.length(); i++)
    {
        lower_words[i] = tolower(lower_words[i]);
    }

    my_file.open(file_name, ios::out);
    if (my_file.is_open()) {
        my_file << lower_words;
        my_file.close();
    }
}

void  count_words(){
    string text;
    int ctr = 0;
    open_file();
    while ( my_file >> text )
        ctr++;
    cout<<ctr;

}


void title_words()
{

    string line, lower_words;
    open_file();

    if (my_file.is_open())
    {
        while (getline(my_file, line))
        {
            lower_words += line;
            lower_words += "\n";
        }
        my_file.close();
    }

    for (int i = 0; i < lower_words.length(); i++)
    {
        lower_words[i] = tolower(lower_words[i]);
    }

    for (int i = 0; i < lower_words.length(); i++)
    {
        if (i == 0)
        {
            lower_words[i] = toupper(lower_words[i]);
        }
        else if (lower_words[i] == ' ')
        {
            lower_words[i] = lower_words[i];
            lower_words[i + 1] = toupper(lower_words[i]);
        }
        else
        {
            lower_words[i] = lower_words[i];
        }
    }

    my_file.open(file_name, ios::out);
    if (my_file.is_open())
    {
        my_file << lower_words;
        my_file.close();
    }
}

void count_char()
{
    int ctr = 0;
    char c ;
    open_file();
    while( 1 ){
        c = my_file.get() ;
        if ( isalpha(c))
            ctr++;
        if ( c == EOF){
            cout<<ctr;
            break;
        }
    }
}

void count_lines()
{
    string line ;
    int ctr = 0;
    open_file();
    while (getline(my_file , line))
        ctr++;
    cout<<ctr;

}

void look_for_word ()
{
    string word,temp ;
    open_file();
    cout<<"enter the word you are looking for  ";
    cin>>word;
    while (my_file)
    {
        my_file >> temp;
        if (temp == word){
            cout<<"FOUND\n";
            return;
        }
    }
    cout<<"NOT FOUND\n";
}

void merge_files(){
    open_file();
    ofstream original_file ;
    ifstream new_file ;
    original_file.open(file_name, ios_base::app);
    cout<<"enter the other file name  ";
    getline(cin, file_name);
    new_file.open(file_name);
    while (new_file.fail())
    {
        cout << file_name << " is not a file name, try again!  ";
        cin.clear();
        cin.sync();
        getline(cin, file_name);
        new_file.open(file_name, ios::in);
    }
    original_file<< new_file.rdbuf() <<endl;
    original_file.close();
    new_file.close();
}

void display_content()
{
    ifstream dataFile; 
    char fileName[81];
    cout << "Enter the name of a file: ";
    cin.getline(fileName, 81);
    dataFile.open(fileName);
    if (dataFile.fail()) 
    {
        cout << "File open error!" << endl;
    }
    else
    {
    cout << "File opened successful.\n";
    cout << "Now reading information.\n";
    int ctr = 0;
    while (true)
    {
        char c;
        c = my_file.get();
        if (isalpha(c))
        {
            ctr++;
        }
        if (c == EOF)
        {
            break;
        }
    }
    char name[ctr];
    dataFile >> name;
    cout << name << endl;
    dataFile.close();
}
}


int main()
{
    int choice;
    cout<<"choose the operation you want\n"
    <<"1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n4. Encrypt the file content\n"
    <<"5. Decrypt the file content\n6. Merge another file\n7. Count the number of words in the file.\n8. Count the number of characters in the file\n"
    <<"9. Count the number of lines in the file\n10. Search for a word in the file\n11. Count the number of times a word exists in the file\n"
    <<"12. Turn the file content to upper case.\n13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital)\n"
    <<"15. Save\n16. Exit\n"
    << "Enter the number of operation: ";
    cin >> choice;
    cin.ignore();
    if (choice == 2)
    {
        display_content();
        main();
    }
    
    if (choice == 6){
        merge_files();
    }
    if ( choice == 7){
        count_words();
    }
    if (choice == 8){
        count_char();
    }
    if ( choice == 9){
        count_lines();
    }
    if ( choice == 10){
        look_for_word();
    }
    if (choice==11)
    {
        repeated_word();
    }
    else if (choice == 12)
    {
        upper_words();
    }
    else if(choice == 13)
        lower_words();

    else if (choice == 14 )
        title_words();
}
