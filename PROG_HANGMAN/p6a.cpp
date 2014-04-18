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
	ifstream fs;
	cout << "FILENAME ? ";
	cin >> file;

	fs.open(file, ifstream::in);								//tenta abrir ficheiro 
	if (!fs.is_open()) cout << "ERROR: File not found!" << endl;//se não consegue abrir ficheiro é porque não o encontrou 
	else{
		while (getline(fs, line)) cout << line << endl;			//enquanto nao chegar ao fim do ficheiro extrai linhas e mostra na consola
	}
	fs.close();													//fecha ficheiro
	_getch();
}