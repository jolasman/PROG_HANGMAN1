#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <time.h>       /* time */

using namespace std;

#include "p5.h"

void p5_function()
{
	cout << "NUMBER A ? ";
	int a;
	cin >> a;
	cout << "NUMBER B ? ";
	int b;
	cin >> b;
	//se a > b??
	int randN;
	srand((unsigned int)time(NULL));
	randN = rand() % (b - a + 1) + a;
	cout << "Number generated randomly in the interval [" << a << ".." << b << "]: " << randN << endl;
}