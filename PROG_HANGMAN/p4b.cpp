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

	cout << "SENTENCE ? ";
	string s;
	getline(cin, s);
	cout << "RESULT   : ";
	for (unsigned int i = 0; i < s.length(); i++)
	{
		c = s[i];
		present = 0;
		if (c == ' ') cout << " ";
		else{
			if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
			for (unsigned int j = 0; j < letters.size(); j++)
			{
				if (letters[j] == (char)c) {
					present = 1; break;
				}
			}
			if (present == 1) cout << s[i];
			else cout << "*";
		}
	}
	cout << endl;
	_getch();
}