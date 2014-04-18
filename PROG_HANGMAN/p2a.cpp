#include <sstream>
#include <iostream>
#include <conio.h>
using namespace std;


void main()
{
	cout << "STRING  ? ";
	string s;
	cin >> s;

	int sum = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		//fazer a verificacao se o carater introduzido e um valor de 0 a 9 e nao outro qualquer
		if (((int)s[i]<48) || ((int)s[i]>57))
		{
			cout << "Invalid chars" << endl;
			_getch();
			return;
		}
		sum += (s[i] - 48) * (int)pow(10.0, (s.length() - i - 1));
	}

	cout << "INTEGER : " << sum << endl;
	_getch();
}