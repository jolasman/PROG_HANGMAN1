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
	//cout << "string length: " << s.length() << endl;
	for(int i = s.length()-1; i >= 0; i--){
		if (((int)s[i]<48) || ((int)s[i]>57))
		{
			cout << "Invalid chars: \"" << s[i] << "\" = " << (int)s[i] << endl;
			return;
		}
		soma += ((int)s[i] - 48)* pow(10, s.length() - i - 1);
		//cout << "soma : " << soma << endl;
	}

	cout << "INTEGER : " << soma << endl;
}


/*void p2b_function()
{
cout << "SENTENCE ?" << endl;


	
	cout << "SENTENCE IN UPPERCASE: ";
	cout <<  << endl;
}

*/