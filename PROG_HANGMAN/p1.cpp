#include <stdio.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include "p1.h"

/*
*
*esta função deveria so ler palavras juntas contudo le ja com palavras separadas como pede no p1b
*
*/

void p1a_function()
{
cout << "WORD ?" << endl;


string imput = " ";
cin >> imput;

for(int i = 0 ; i < imput.length(); i++){
	imput[i] = toupper(imput[i]);
	
	
}
	
	cout << "WORD IN UPPERCASE: ";
	cout << imput << endl;
}


void p1b_function()
{
cout << "SENTENCE ?" << endl;


string imput = " ";
getline(cin , imput);

for(int i = 0 ; i < imput.length(); i++){
	imput[i] = toupper(imput[i]);
	
	
}
	
	cout << "SENTENCE IN UPPERCASE: ";
	cout << imput << endl;
}

