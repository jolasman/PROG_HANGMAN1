#include <sstream>
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

void main()
{
	int c;
	do {
		cout << "LETTER ? ";
		c = _getch();
		cout << (char)c << endl;
	} while (!((c >= 'a') && (c <= 'z')) && !((c >= 'A') && (c <= 'Z')));
	_getch();
}