#include <sstream>
#include <iostream>
using namespace std;

#include "p2.h"


void p2a_function()
{
	cout << "STRING  ? ";
	string s;
	cin >> s;
	
	int soma = 0;
	
	for(int i = s.length()-1; i >= 0; i--)
	{
		//fazer a verificacao se o carater introduzido e um valor de 0 a 9 e nao outro qualquer
		if (((int)s[i]<48) || ((int)s[i]>57))
		{
			cout << "Invalid char: \"" << s[i] << "\" = " << (int)s[i] << endl;
			return;
		}

		soma += ((int)s[i] - 48)* (double) pow((double)10.0, (int)(s.length() - i - 1));
		
	}

	cout << "INTEGER : " << soma << endl;
}


void p2b_function()
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
}
