#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <conio.h>

using namespace std;

void main()
{
	string file, line;
	unsigned int nlines = 0, exp = 0;
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
				_getch();
				return;
			}
			nlines += ((int)line[i] - 48)* (int)pow((double)10.0, (int)exp);
			exp++;
		}
		srand((unsigned int)time(NULL));
		int randN = rand() % nlines + 1;							//escolhe uma linha aleatoriamente
		for (int i = 0; i < randN; i++) getline(fs, line);			//extrai linhas ate chegar a selecionada por 'rand()'
		cout << "SENTENCE: " << line << endl;						//mostra na consola a linha
	}
	fs.close();
	_getch();
}