#ifndef func10_H
#define func10_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <conio.h>

struct Score_info {
	std::string name;
	int score;
};
extern int trials;

int rand_int(int a, int b);
int string_to_int(std::string s);
std::string int_to_string(int n);
std::string get_sentence(std::string filename);
std::string string_to_upper(std::string s);
std::string unhide_letters(std::string s, std::vector<char> letters);
void show_vector_char(std::vector<char> v);
bool show_file(std::string filename);
unsigned int count_letters(std::string s);
unsigned int count_diff_letters(std::string s);
unsigned int calculate_score(std::string s, unsigned int tnm, unsigned int t);
std::vector<Score_info> get_best_scores(std::string filename);
void show_best_scores(const std::vector<Score_info> &best_scores);
void update_best_scores(std::vector<Score_info>& best_scores, const Score_info &si);
void save_best_scores(std::string filename, const std::vector<Score_info> &best_scores, int n_best);
bool input(std::string s, std::vector <char> &v);


#endif