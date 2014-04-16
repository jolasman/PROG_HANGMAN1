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
		c = _getch();														//regista e guarda na variavel 'c' a tecla premida
		cout << (char) c << endl;											//mostra na consola a tecla premida
	} while (!((c >= 'a') && (c <= 'z')) && !((c >= 'A') && (c <= 'Z')));	//enquanto a tecla premida nao for uma letra (nao estiver nos intervalos a-z ou A-Z) repete o ciclo
}


void p3b_function()
{
	int c;
	vector <char> letters;									//vector para guardar variaveis premidas
	bool existe;

	do {
		cout << "LETTER ? ";
		c = _getch();										//regista e guarda na variavel 'c' a tecla premida
		cout << (char)c << endl;							//mostra na consola a tecla premida
		if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
		if ((c >= 'A') && (c <= 'Z'))						//se for letra (ja esta em uppercase), corre o vector para ver se já existe
		{
			existe = 0;
			for (unsigned int i = 0; i < letters.size(); i++)
			{
				if (letters[i] == (char)c) { existe = 1; break; }//se encontrou a letra no vector, regista que encontrou e termina pesquisa
			}
			if (existe == 0) letters.push_back((char) c);	//se não existe, insere a letra no vector
		}
	} while (c != '.');										//enquanto nao for premida a tecla de '.' repete o ciclo

	cout << "VECTOR: [ ";
	for (unsigned int i = 0; i < letters.size(); i++)		//percorre o vector e exibe na consola as letras recolhidas
	{
		cout << letters[i] << " ";
	}
	cout << "]" << endl;
}