#include <sstream>
#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	cout << "WORD ? ";
	string input;
	cin >> input;
	cin.ignore(10000, '\n'); //"limpa" a cin no caso de terem sido inseridas mais que uma palavra

	for (int i = 0; i < input.length(); i++)
	{
		input[i] = toupper(input[i]);
	}

	cout << "WORD IN UPPERCASE: ";
	cout << input << endl;
	_getch();
}