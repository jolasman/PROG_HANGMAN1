#include <stdio.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
 
#include "p1.h"

void p1a_function()
{
	cout << "WORD ? ";
	string input;
	cin >> input;
	cin.ignore(10000, '\n'); //"limpa" a cin no caso de terem sido inseridas mais que uma palavra

	for(int i = 0 ; i < input.length(); i++)
	{
		input[i] = toupper(input[i]);
	}

	cout << "WORD IN UPPERCASE: ";
	cout << input << endl;
}


void p1b_function()
{
	cout << "SENTENCE ? ";
	string input;
	getline(cin, input);

	for(int i = 0 ; i < input.length(); i++)
	{
		input[i] = toupper(input[i]);
	}

	cout << "SENTENCE IN UPPERCASE: ";
	cout << input << endl;
}

