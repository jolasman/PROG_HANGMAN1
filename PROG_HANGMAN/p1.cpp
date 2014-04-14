#include <stdio.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include "p1.h"

/*
*
*esta função deveria so ler palavras juntas contudo le ja com palavras separadas como pede no p1b
*
*/

void p1a_function()
{
	cout << "WORD ? ";
	string input;
	cin >> input;
	cin.ignore(10000, '\n');

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

