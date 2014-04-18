#include <sstream>
#include <iostream>
#include <conio.h>
using namespace std;


void main()
{
	cout << "INTEGER ? ";

	int i, temp, rem;

	cin >> i;
	temp = i;
	string s;

	if (i == 0) s = (char)(48);

	while (temp > 0)
	{
		rem = temp % 10;
		s = (char)(rem + 48) + s;
		temp = temp / 10;
	}
	cout << "STRING  ? " << s << endl;
	_getch();
}