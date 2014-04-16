#include <stdio.h> /* printf, scanf, puts, NULL */
#include <iostream>
using namespace std;
#include <fstream>// trabalhar com ficheiros
#include <sstream>
#include <stdlib.h>
#include <time.h>

#include "p6.h"


void p6a_function(){

	cout << " name of .txt ?" << endl;
	string name;

	cin >> name;
	string n;
	
	//e preciso fazer a parte de chamar o .txt com o nome dado pelo utilizador
	
 ifstream myfile ("beatles.txt");

  if(myfile.is_open())
  {
    while (!myfile.eof())
	{
		getline(myfile,n);

		int N = 0;
	
		for(int i = n.length()-1; i >= 0; i--)
		{
		//fazer a verificacao se o carater introduzido e um valor de 0 a 9 e nao outro qualquer
			if (((int)n[i]<48) || ((int)n[i]>57))
		{
			cout << "Invalid char: \"" << n[i] << "\" = " << (int)n[i] << endl;
			return;
		}

		N += ((int)n[i] - 48)* (double) pow((double)10.0, (int)(n.length() - i - 1));
		
	}
		//calcular o valor de K aleatorio
		int k;
		int a = 1;
	srand((unsigned int)time(NULL));
	k = rand() % (N - a + 1) + a;




	}

}else
  {
	  cout<<"erro ao abrir o ficheiro. tente outro nome\n";
  }

    myfile.close();
  }
  

