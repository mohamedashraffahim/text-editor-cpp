#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

fstream my_file;
string file_name;
string content, content2;
int c;

void check_operation(string& number);

void open_file();

void repeated_word();

void upper_words();

void lower_words();

void count_words();

void title_words();

void count_char();

void count_lines();

void look_for_word();

void merge_files();

void display_content();

void delete_content();

void add_text();

void cipher();

void decipher();

void save_file();

#endif // HEADER_H_INCLUDED