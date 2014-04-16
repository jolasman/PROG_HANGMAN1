#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <time.h>       /* time */

using namespace std;

#include "p5.h"

void p5_function()
{
	srand((unsigned int)time(NULL));
	int a, b, randN;
	cout << "NUMBER A ? ";
	cin >> a;
	cout << "NUMBER B ? ";
	cin >> b;

	//se a > b??
	randN = rand() % (b - a + 1) + a;
	
	cout << "Number generated randomly in the interval [" << a << ".." << b << "]: " << randN << endl;
}