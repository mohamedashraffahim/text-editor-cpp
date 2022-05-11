// FCAI - Structured Programming - 2022 - Assignment 4
//Program Name : text editor
// Program Description : this program takes a file chosed by the user and applies changes on that file as the user wants
// Author1 :  Mohamed Ashraf Fahim         ID:20210329       Group: A
// Author2 :  Momen Mostafa Mabrouk        ID:20210416       Group: A
// Author3 :  Mariam Esmat Ahmed           ID:20211091       Group: A
// ver2 of Date : 7th of May 2022
//section 9,10

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

fstream my_file;
string file_name;
string content;
int c;



//makes sure tha the chosen opertion is an intger number
void check_operation(string& number)
{
    //takes the chosen opertaion as a string
    string chosen_opperation;
    //loops through that string
    for (int i = 0; i < number.length(); i++)
    {
        //if i is a digit it is appeanded
        if (isdigit(number[i]))
        {
            chosen_opperation.push_back(number[i]);
        }
    }
    //lenght of the string is not the same anymore it means that it icnulded a letter
    if (chosen_opperation.length() != number.length())
    {
        //ask the user to enter a new chioce
        cout << "Invalid input, please try again: ";
        cin >> number;
        cin.ignore();
        //re-apply the same function
        check_operation(number);
    }
}
void open_file()
{
    cout << "Enter name of file you want to open and its extention ex: file called \"test.txt\" in folder: ";
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
    cin.clear(), cin.sync();
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

            if (text == word || text == word + '.' || text == word + ',' || text == '.' + word || text == ',' + word)
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
    cin.clear(), cin.sync();
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
    cin.clear(), cin.sync();
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
    if (my_file.is_open())
    {
        my_file << lower_words;
        my_file.close();
    }
}

void  count_words()
{
    string text;
    int ctr = 0;
    open_file();
    while (my_file >> text)
        ctr++;
    cout << ctr;

}


void title_words()
{
    string line, lower_words;
    open_file();
    cin.clear(), cin.sync();

    if (my_file.is_open())
    {
        while (getline(my_file, line))
        {
            lower_words += line;
            lower_words += "\n";

            transform(lower_words.begin(), lower_words.end(), lower_words.begin(), ::tolower);


            for (int i = 0; i < lower_words.length() - 1; ++i)
            {
                lower_words[0] = toupper(lower_words[0]);
                if (lower_words[i] == ' ' || lower_words[i] == '\n' && lower_words[i + 1] != ' ')
                {
                    lower_words[i + 1] = toupper(lower_words[i + 1]);

                }

            }

        }
        my_file.close();
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
    char c;
    open_file();
    while (1)
    {
        c = my_file.get();
        if (isalpha(c))
            ctr++;
        if (c == EOF)
        {
            cout << ctr;
            break;
        }
    }
}

void count_lines()
{
    string line;
    int ctr = 0;
    open_file();
    while (getline(my_file, line))
        ctr++;
    cout << ctr;

}

void look_for_word()
{
    string word, temp;
    open_file();
    cout << "enter the word you are looking for  ";
    cin >> word;
    while (my_file)
    {
        my_file >> temp;
        if (temp == word)
        {
            cout << "FOUND\n";
            return;
        }
    }
    cout << "NOT FOUND\n";
}

void merge_files()
{
    open_file();
    ofstream original_file;
    ifstream new_file;
    original_file.open(file_name, ios_base::app);
    cout << "enter the other file name  ";
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
    original_file << new_file.rdbuf() << endl;
    original_file.close();
    new_file.close();
}

void display_content()
{
    open_file();
        while(! my_file.eof())
        {
            getline(my_file, content);
            cout << content << endl;
        }
    my_file.close();
}


void delete_content()
{
    ofstream ofile;
    open_file();
    my_file.close();
    ofile.open(file_name, ofstream::out | ofstream::trunc);   
    if (ofile.fail()) 
    {
        cout << "File open error!" << endl;
    }
    else
    {
    cout << "File opened successful.\n";
    }
    ofile.close();
}

void add_text()
{
    ofstream ofile;
    string data;
    open_file();
    my_file.close();
    ofile.open(file_name, ios_base::app);   
    cout << "Please enter the data you want to append: ";
    cin.clear();
    cin.sync();
    getline(cin, data);
    ofile << data;
    ofile.close();
}

void cipher()
{
    open_file();
    while (my_file)
    {
        char ch;
        my_file.get(ch);
        c+=1;
    }
    my_file.close();
    ifstream dataFile2;
    dataFile2.open(file_name);
    int ctr = 0;
    char name[c-1], name2[c-1];
        while(! dataFile2.eof())
        {
            getline(dataFile2, content);
        }
    strcpy(name, content.c_str());
    strncpy(name2, name, c-1);
    for (int i = 0; i < (c-1)  ; i++)
    {
       name2[i] = name[i] + 1;
    }
    dataFile2.close();
    ofstream ofile;
    ofile.open(file_name, ofstream::out | ofstream::trunc);
    ofile.close();
    ofstream ofile2;
    ofile2.open(file_name, ios_base::app);   
    ofile2 << name2;
    ofile2.close();
}

void decipher()
{
    open_file();
    while (my_file)
    {
        char ch;
        my_file.get(ch);
        c+=1;
    }
    my_file.close();
    ifstream dataFile2;
    dataFile2.open(file_name);
    int ctr = 0;
    char name[c-1], name2[c-1];
        while(! dataFile2.eof())
        {
            getline(dataFile2, content);
        }
    strcpy(name, content.c_str());
    strncpy(name2, name, c-1);
    for (int i = 0; i < (c-1)  ; i++)
    {
       name2[i] = name[i] - 1;
    }
    dataFile2.close();
    ofstream ofile;
    ofile.open(file_name, ofstream::out | ofstream::trunc);
    ofile.close();
    ofstream ofile2;
    ofile2.open(file_name, ios_base::app);   
    ofile2 << name2;
    ofile2.close();
}

void save_file()
{
    ifstream sfile;
    ofstream tfile;
    string source_file;
    string target_file;
    string line, lower_words;
    char ch;
    cout << "Enter a name of the source file and its extention ex: file called \"test.txt\" : ";
    getline(cin, source_file);
    sfile.open(source_file);
    if (sfile.fail())
    {
        cout << "Error in opening file!" << endl;

    }

    cout << "\nEnter a name for the new file you want to save and its extention ex: file called \"test2.txt\" : ";
    getline(cin, target_file);
    tfile.open(target_file);
    if (tfile.fail())
    {
        cout << "Error in opening file!" << endl;
        sfile.close();

    }
    while (sfile.eof() == 0)
    {
        while (getline(sfile, line))
        {
            lower_words += line;
            lower_words += "\n";
        }
        tfile << lower_words;

    }
    cout << "File is copied/saved to another file successfully :)";
    sfile.close();
    tfile.close();

}

int main()
{
    while (1)
    {



        cout << "\nchoose the operation you want\n"
            << "1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n4. Encrypt the file content\n"
            << "5. Decrypt the file content\n6. Merge two files\n7. Count the number of words in the file.\n8. Count the number of characters in the file\n"
            << "9. Count the number of lines in the file\n10. Search for a word in the file\n11. Count the number of times a word exists in the file (case insensitive)\n"
            << "12. Turn the file content to upper case.\n13. Turn the file content to lower case.\n14. Turn file content to title format (1st char of each word is capital)\n"
            << "15. Save content to a new file\n16. Exit\n"
            << "Enter the number of operation: ";
        string chosen_opperation;
        cin >> chosen_opperation;
        cin.ignore();
        cout << "\n";
        check_operation(chosen_opperation);
        int choice = stoi(chosen_opperation);
        cin.ignore();

        //terminates the program
        if (choice == 16)
        {
            cout << "Thank you for using our program :)\n";
            break;
        }

        if (choice > 0 && choice < 16)
        {
            if (choice == 1)
            {
                add_text();
            }
            if (choice == 2)
            {
                display_content();
            }
            if (choice == 3)
            {
                delete_content();
            }
            if (choice == 4)
            {
                cipher();
            }
            if (choice == 5)
            {
                decipher();
            }
            if (choice == 6)
            {
                merge_files();
            }
            if (choice == 7)
            {
                count_words();
            }
            if (choice == 8)
            {
                count_char();
            }
            if (choice == 9)
            {
                count_lines();
            }
            if (choice == 10)
            {
                look_for_word();
            }
            if (choice == 11)
            {
                repeated_word();
            }
            if (choice == 12)
            {
                upper_words();
            }
            if (choice == 13)
            {
                lower_words();
            }
            if (choice == 14)
            {
                title_words();
            }
            if (choice == 15)
            {
                save_file();
            }
        }

        //gets the user back to choose the operation if he enters a wrong input
        else
        {
            cout << "Sorry, your input is invalid. Please try again ! " << endl;
            main();
            cout << "\n";
        }
    }
}
