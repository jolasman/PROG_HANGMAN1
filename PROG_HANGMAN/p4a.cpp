#include <sstream>
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

void main()
{
	int c;
	vector <char> letters;
	bool exists, present;
	do {
		cout << "LETTER ? ";
		c = _getch();
		cout << (char)c << endl;
		if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
		if ((c >= 'A') && (c <= 'Z'))						//se for letra (ja esta em uppercase) corre o vector para ver se já exists
		{
			exists = 0;
			for (unsigned int i = 0; i < letters.size(); i++)
			{
				if (letters[i] == (char)c) {
					exists = 1; break;
				}
			}
			if (exists == 0) letters.push_back((char)c);	//se não exists, insere a letra no vector
		}
	} while (c != '.');

	cout << "VECTOR: [ ";
	for (unsigned int i = 0; i < letters.size(); i++)		//corre o vector para exibir na consola as letras recolhidas
	{
		cout << letters[i] << " ";
	}
	cout << "]" << endl << endl;

	cout << "LETTER TO SEARCH ? ";
	c = _getch();
	cout << (char)c << endl;
	if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
	present = 0;
	for (unsigned int i = 0; i < letters.size(); i++)
	{
		if (letters[i] == (char)c) {
			present = 1; break;
		}
	}
	if (present == 1) cout << "letter " << (char)c << " belongs to the vector" << endl;
	else cout << "letter " << (char)c << " doesn't belong to the vector" << endl;
	_getch();
}
