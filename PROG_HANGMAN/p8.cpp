#include <stdio.h>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

#include "p7.h"

bool input(string s, vector <char> &v)
{
	int c;
	s = string_to_upper(s);
	bool cont = 0, present = 0;
	do {
		cout << "BET (LETTER)  ? ";
		c = _getch();
		cout << (char)c << endl;
		if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
		if ((c >= 'A') && (c <= 'Z'))						//se for letra (ja esta em uppercase) corre o vector para ver se já existe
		{
			cont = 0;
			for (unsigned int i = 0; i < v.size(); i++)
			{
				if (v[i] == (char)c) { cont = 1; break; }
			}
			if (cont == 0) v.push_back((char)c);	//se não existe, insere a letra no vector
		}
		else cont = 1;
	} while (cont == 1);


	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (c == s[i]) {
			present = 1;
			break;
		}
	}
	return present;
}


void hangman()
{
	vector<char> letters;
	string word = get_sentence("beatles.txt");
	int min, max;
	if (word.length() > 9) min = 9;
	else min = word.length();
	if (word.length() * 2 > 9) max = 9;
	else max = word.length() * 2;
	int trials = rand_int(min, max);
	int init_trials = trials;
	cout << "HANGMAN" << endl << endl;
	cout << "Try to guess the word / sentence" << endl;
	cout << "Each letter is represented by an '*'" << endl;
	cout << "You have " << trials << " trials" << endl << endl;

	while (trials > 0)
	{
		cout << "PREVIOUS BETS : ";
		show_vector_char(letters);
		cout << "KNOWN LETTERS : " << unhide_letters(word, letters) << endl;
		//verificar se ainda há asteriscos
		if (unhide_letters(word, letters).find("*") == std::string::npos)
		{
			cout << "YOU ARE A WINNER. CONGRATULATIONS !" << endl;
			_getch();
			return;
		}
		if (!input(word, letters)){
			trials--;
		}
		if (trials != init_trials) show_file("fig" + int_to_string(trials+1) + ".txt");
	}
	cout << endl << "The word / sentence was : " << word << endl << endl;
	cout << "YOU HAVE LOST ! WE ARE GOING TO CALL THE UNDERTAKERS :-(" << endl;
}