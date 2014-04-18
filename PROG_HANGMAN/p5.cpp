#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <conio.h>

 
using namespace std;

void main()
{
	cout << "NUMBER A ? ";
	int a;
	cin >> a;
	cout << "NUMBER B ? ";
	int b;
	cin >> b;
	int randN;
	srand((unsigned int)time(NULL));
	randN = rand() % (b - a + 1) + a;
	cout << "Number generated randomly in the interval [" << a << ".." << b << "]: " << randN << endl;
	_getch();
}