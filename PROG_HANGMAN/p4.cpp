#include <sstream>
#include <iostream>
#include <conio.h>
#include <vector>
 
using namespace std;

#include "p4.h"

void p4a_function()
{
	int c;
	vector <char> letters;
	bool existe, presente;
	do {
		cout << "LETTER ? ";
		c = _getch();
		cout << (char)c << endl;
		if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
		if ((c >= 'A') && (c <= 'Z'))						//se for letra (ja esta em uppercase) corre o vector para ver se j� existe
		{
			existe = 0;
			for (unsigned int i = 0; i < letters.size(); i++)
			{
				if (letters[i] == (char)c) existe = 1;
			}
			if (existe == 0) letters.push_back((char)c);	//se n�o existe, insere a letra no vector
		}
	} while (c != '.');

	cout << "VECTOR: [ ";
	for (unsigned int i = 0; i < letters.size(); i++)		//corre o vector para exibir na consola as letras recolhidas
	{
		cout << letters[i] << " ";
	}
	cout << "]" << endl << endl;
	
	cout << "LETTER TO SEARCH ? ";
	c = _getch();
	cout << (char)c << endl;
	if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
	presente = 0;
	for (unsigned int i = 0; i < letters.size(); i++)
	{
		if (letters[i] == (char)c) presente = 1;
	}
	if (presente == 1) cout << "letter " << (char) c << " belongs to the vector" << endl;
	else cout << "letter " << (char)c << "doesn't belong to the vector" << endl;
}


void p4b_function()
{
	int c;
	vector <char> letters;
	bool existe, presente;
	do {
		cout << "LETTER ? ";
		c = _getch();
		cout << (char)c << endl;
		if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
		if ((c >= 'A') && (c <= 'Z'))						//se for letra (ja esta em uppercase) corre o vector para ver se j� existe
		{
			existe = 0;
			for (unsigned int i = 0; i < letters.size(); i++)
			{
				if (letters[i] == (char)c) existe = 1;
			}
			if (existe == 0) letters.push_back((char)c);	//se n�o existe, insere a letra no vector
		}
	} while (c != '.');

	cout << "VECTOR: [ ";
	for (unsigned int i = 0; i < letters.size(); i++)		//corre o vector para exibir na consola as letras recolhidas
	{
		cout << letters[i] << " ";
	}
	cout << "]" << endl << endl;

	cout << "SENTENCE ? ";
	string s;
	getline(cin, s);
	cout << "RESULT   : ";
	for (unsigned int i = 0; i < s.length(); i++)
	{
		c = s[i];
		presente = 0;
		if (c == ' ') cout << " ";
		else{
			if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
			for (unsigned int j = 0; j < letters.size(); j++)
			{
				if (letters[j] == (char)c) presente = 1;
			}
			if (presente == 1) cout << s[i];
			else cout << "*";
		}
	}
	cout << endl;
}