#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>       /* time */

int rand_int(int a, int b)
{
	int randN;
	srand((unsigned int)time(NULL));
	randN = rand() % (b - a + 1) + a;
	return randN;
}

int string_to_int(std::string s)
{
	int sum = 0;

	for (int i = s.length()-1; i >= 0; i--)
	{
		sum += (s[i] - 48)* (int)pow( 10, s.length() - i - 1);
	}
	return sum;
}

std::string int_to_string(int n)
{
	int temp, rem;
	temp = n;
	std::string s;

	if (n == 0) s = (char)(48);
	while (temp > 0)
	{
		rem = temp % 10;
		s = (char)(rem + 48) + s;
		temp = temp / 10;
	}
	
	return s;
}

std::string get_sentence(std::string filename)
{
	std::string line;
	unsigned int nlines = 0, exp = 0;
	std::ifstream fs;

	fs.open(filename, std::ifstream::in);									//tenta abrir ficheiro 
	if (!fs.is_open()){
		std::cout << "ERROR: File not found!" << std::endl;	//se nao consegue abrir ficheiro e' porque nao o encontrou
		return "";
	}
	else{
		getline(fs, line);											//extrai a primeira linha para ver se contem o numero de linhas  
		nlines = string_to_int(line);
		srand((unsigned int)time(NULL));
		int randN = rand() % nlines + 1;							//escolhe uma linha aleatoriamente
		for (int i = 0; i < randN; i++) getline(fs, line);			//extrai linhas ate chegar a selecionada por 'rand()'
		return line;
	}
	fs.close();														//fecha ficheiro 
}

std::string string_to_upper(std::string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}

std::string unhide_letters(std::string s, std::vector<char> letters)
{
	std::string c = string_to_upper(s);
	bool presente;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		presente = 0;
		if (c[i] != ' ')
		{
			for (unsigned int j = 0; j < letters.size(); j++)
			{
				if (letters[j] == c[i]) { presente = 1; break; }
			}
			if (presente == 0) s[i]='*';
		}
	}
	return s;
}

void show_vector_char(std::vector<char> v)
{
	std::cout << "[ ";
	for (unsigned int i = 0; i < v.size(); i++)		//corre o vector para exibir na consola as letras recolhidas
	{
		std::cout << v[i] << " ";
	}
	std::cout << "]" << std::endl;
}

bool show_file(std::string filename)
{
	std::ifstream fs;
	std::string line;
	fs.open(filename, std::ifstream::in);							//tenta abrir ficheiro 
	if (!fs.is_open()) return 0;									//se não consegue abrir ficheiro é porque não o encontrou 
	else{
		while (getline(fs, line)) std::cout << line << std::endl;	//enquanto nao chegar ao fim do ficheiro extrai linhas e mostra na consola
	}
	fs.close();		
	return 1;
}