// FCAI - Structured Programming - 2022 - Assignment 4
//Program Name : text editor
// Program Description : this program takes a file chosed by the user and applies changes on that file as the user wants
// Author1 :  Mohamed Ashraf Fahim         ID:20210329       Group: A
// Author2 :  Momen Mostafa Mabrouk        ID:20210416       Group: A
// Author3 :  Mariam Esmat Ahmed           ID:20211091       Group: A
// ver2 of Date : 7th of May 2022
//section 9,10
#include "functions.cpp"

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