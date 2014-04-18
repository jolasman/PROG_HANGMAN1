#include <sstream>
#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	cout << "SENTENCE ? ";
	string input;
	getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		input[i] = toupper(input[i]);
	}

	cout << "SENTENCE IN UPPERCASE: ";
	cout << input << endl;
	_getch();
}