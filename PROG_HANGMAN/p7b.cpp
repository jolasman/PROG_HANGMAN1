#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include <conio.h>

using namespace std;

std::string string_to_upper(std::string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}

std::string unhide_letters(std::string s, std::vector<char> &letters)
{
	std::string c = string_to_upper(s);
	bool present;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		present = 0;
		if (c[i] != ' ')
		{
			for (unsigned int j = 0; j < letters.size(); j++)
			{
				if (letters[j] == c[i]) { present = 1; break; }
			}
			if (present == 0) s[i] = '*';
		}
	}
	return s;
}

void show_vector_char(std::vector<char> &v)
{
	std::cout << "[ ";
	for (unsigned int i = 0; i < v.size(); i++)		//corre o vector para exibir na consola as letras recolhidas
	{
		std::cout << v[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void main()
{
	/*Testes da p7a*/
	string s;
	vector<char> letters;

	letters.push_back('S');
	letters.push_back('T');
	letters.push_back('B');
	letters.push_back('L');
	letters.push_back('I');
	letters.push_back('E');
	s = unhide_letters("Sport Lisboa e Benfica", letters);
	cout << "Sentence: " << s << endl << endl;

	cout << "VECTOR: ";
	show_vector_char(letters);

	_getch();
}