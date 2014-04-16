#include <stdio.h>
#include <stdlib.h>		/* srand, rand */
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>		/* time */

using namespace std;

#include "p6.h"

void p6a_function()
{
	string file, line;
	ifstream fs;
	cout << "FILENAME ? ";
	cin >> file;

	fs.open(file, ifstream::in);								//tenta abrir ficheiro 
	if (!fs.is_open()) cout << "ERROR: File not found!" << endl;//se não consegue abrir ficheiro é porque não o encontrou 
	else{
		while (getline(fs, line)) cout << line << endl;			//enquanto nao chegar ao fim do ficheiro extrai linhas e mostra na consola
	}
	fs.close();													//fecha ficheiro 
}


void p6b_function()
{
	string file, line;
	unsigned int nlines=0, exp=0;
	ifstream fs;
	cout << "FILENAME? ";
	cin >> file;

	fs.open(file, ifstream::in);									//tenta abrir ficheiro 
	if (!fs.is_open()) cout << "ERROR: File not found!" << endl;	//se nao consegue abrir ficheiro e' porque nao o encontrou 
	else{
		getline(fs, line);											//extrai a primeira linha para ver se contem o numero de linhas  
		/* Converter a string em inteiro (p2a)*/
		for (int i = line.length() - 1; i >= 0; i--){
			if (((int)line[i]<48) || ((int)line[i]>57))
			{
				cout << "ERROR: First line is not a valid number (should be number of lines of the file). " << endl;
				return;
			}
			nlines += ((int)line[i] - 48)* (int)pow(10, exp);
			exp++;
		}
		srand((unsigned int)time(NULL));
		int randN = rand() % nlines + 1;							//escolhe uma linha aleatoriamente
		for (int i = 0; i < randN; i++) getline(fs, line);			//extrai linhas ate chegar a selecionada por 'rand()'
		cout << "SENTENCE: " << line << endl;						//mostra na consola a linha
	}
	fs.close();														//fecha ficheiro 
}