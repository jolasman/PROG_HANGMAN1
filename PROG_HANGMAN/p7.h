#ifndef p7_H
#define p7_H

#include <vector>

int rand_int(int a, int b);
int string_to_int(std::string s);
std::string int_to_string(int n);
std::string get_sentence(std::string filename);
std::string string_to_upper(std::string s);
std::string unhide_letters(std::string s, std::vector<char> letters);
void show_vector_char(std::vector<char> v);
bool show_file(std::string filename);

#endif