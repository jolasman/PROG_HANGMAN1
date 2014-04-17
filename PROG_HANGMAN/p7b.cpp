#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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
	std::cout << "VECTOR: [ ";
	for (unsigned int i = 0; i < v.size(); i++)		//corre o vector para exibir na consola as letras recolhidas
	{
		std::cout << v[i] << " ";
	}
	std::cout << "]" << std::endl;
}