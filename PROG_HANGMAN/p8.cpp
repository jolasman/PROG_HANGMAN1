#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include <conio.h>

using namespace std;

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

	for (int i = s.length() - 1; i >= 0; i--)
	{
		sum += (s[i] - 48)* (int)pow(10, s.length() - i - 1);
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

bool input(string s, vector <char> &v)
{
	int c;
	s = string_to_upper(s);
	bool cont = 0, present = 0;
	do {
		cout << "BET (LETTER)  ? ";
		c = _getch();
		cout << (char)c << endl;
		if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
		if ((c >= 'A') && (c <= 'Z'))						//se for letra (ja esta em uppercase) corre o vector para ver se já existe
		{
			cont = 0;
			for (unsigned int i = 0; i < v.size(); i++)
			{
				if (v[i] == (char)c) { cont = 1; break; }
			}
			if (cont == 0) v.push_back((char)c);	//se não existe, insere a letra no vector
		}
		else cont = 1;
	} while (cont == 1);


	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (c == s[i]) {
			present = 1;
			break;
		}
	}
	return present;
}


void main()
{
	vector<char> letters;
	string word = get_sentence("beatles.txt");
	int min, max;
	if (word.length() > 9) min = 9;
	else min = word.length();
	if (word.length() * 2 > 9) max = 9;
	else max = word.length() * 2;
	int trials = rand_int(min, max);
	int init_trials = trials;
	cout << "HANGMAN" << endl << endl;
	cout << "Try to guess the word / sentence" << endl;
	cout << "Each letter is represented by an '*'" << endl;
	cout << "You have " << trials << " trials" << endl << endl;

	while (trials > 0)
	{
		cout << "PREVIOUS BETS : ";
		show_vector_char(letters);
		cout << "KNOWN LETTERS : " << unhide_letters(word, letters) << endl;
		//verificar se ainda há asteriscos
		if (unhide_letters(word, letters).find("*") == std::string::npos)
		{
			cout << endl << "YOU ARE A WINNER. CONGRATULATIONS !" << endl;
			_getch();
			return;
		}
		if (!input(word, letters)){
			trials--;
		}
		if (trials != init_trials) show_file("fig" + int_to_string(trials+1) + ".txt");
	}
	cout << endl << "The word / sentence was : " << word << endl << endl;
	cout << "YOU HAVE LOST ! WE ARE GOING TO CALL THE UNDERTAKERS :-(" << endl;
	_getch();
}