#include <sstream>
#include <iostream>
#include <conio.h>
#include <vector>
 
using namespace std;

#include "p3.h"

void p3a_function()
{
	int c;
	do {
		cout << "LETTER ? ";
		c = _getch();
		cout << (char) c << endl;
	} while (!((c >= 'a') && (c <= 'z')) && !((c >= 'A') && (c <= 'Z')));
}


void p3b_function()
{
	int c;
	vector <char> letters;
	bool existe;
	do {
		cout << "LETTER ? ";
		c = _getch();
		cout << (char)c << endl;
		if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
		if ((c >= 'A') && (c <= 'Z'))						//se for letra (ja esta em uppercase) corre o vector para ver se já existe
		{
			existe = 0;
			for (unsigned int i = 0; i < letters.size(); i++)
			{
				if (letters[i] == (char)c) existe = 1;
			}
			if (existe == 0) letters.push_back((char) c);	//se não existe, insere a letra no vector
		}
	} while (c != '.');

	cout << "VECTOR: [ ";
	for (unsigned int i = 0; i < letters.size(); i++)		//corre o vector para exibir na consola as letras recolhidas
	{
		cout << letters[i] << " ";
	}
	cout << "]" << endl;
}