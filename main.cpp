#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string file_name;
void take_file_name(string& file_name)
{
    cout << "Enter name of file you want to open ex: file called \"test\" in folder: ";

    getline(cin, file_name);
}
void count_words()
{
    fstream my_file;
    string text, word;
    int count = 0;
    take_file_name(file_name);

    my_file.open(file_name, ios::in);
    if (my_file.is_open()) {
        cout << "Enter the word: ";
        cin >> word;

        while (my_file >> text)
        {
            if (text == word || text == word + '.')
                count++;
        }

        my_file.close();
        cout << count << endl;
    }
}

void upper_words()
{
    fstream my_file;
    string line, upper_words;
    take_file_name(file_name);

    my_file.open(file_name, ios::in);
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
        upper_words[i] = toupper(upper_words[i] );
    }

    my_file.open(file_name, ios::out);
    if (my_file.is_open()) {
        my_file << upper_words;
        my_file.close();
    }
}

void lower_words()
{
    fstream my_file;
    string line, lower_words;
    take_file_name(file_name);

    my_file.open(file_name, ios::in);
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
    if (choice==11)
    {
        count_words();
    }
    else if (choice == 12)
    {
        upper_words();
    }
    else if(choice == 13)
    {
        lower_words();
    }
}
