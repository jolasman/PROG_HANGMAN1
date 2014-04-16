#include <sstream>
#include <iostream>
using namespace std;

#include "p2.h"


void p2a_function()
{
	cout << "STRING  ? ";
	string s;
	cin >> s;
	int soma = 0, exp = 0;

	for(int i = s.length()-1; i >= 0; i--){			//começa ciclo no ultimo caracter da string (numero menos significativo) e anda na string para a esquerda 
		if (((int)s[i]<48) || ((int)s[i]>57))		//se algum dos caracteres introduzidos nao for um numero da msg de erro e termina programa
		{
			cout << "Invalid char: \"" << s[i] << "\" = " << (int)s[i] << endl;
			return;
		}
		soma += ((int)s[i] - 48)* (int)pow(10, exp);//acrescenta à soma o char convertido em numero, multiplicado pela potencia de 10 correspondente à posição do algarismo
		exp++;										//exp = 0 para o algarismo menos significativo (10^0 = 1)
	}

	cout << "INTEGER : " << soma << endl;
}


void p2b_function()
{
	cout << "INTEGER ? ";
	int i, temp, rem;
	string s;
	cin >> i;

	temp = i;						//copiar o numero introduzido para uma outra variavel para manter o valor de entrada intacto 
	if (i == 0) s = (char)(48);		//caso o numero introduzido seja igual a zero, a string 's' fica igual ao char "0" e salta o ciclo while
	while (temp > 0)
	{
		rem = temp % 10;			//rem é igual ao resto da divisao por 10, logo é igual ao algarismo menos significativo
		s = (char)(rem + 48) + s;	//adiciona o algarismo anterior ao inicio da string 's' na forma de 'char'
		temp = temp / 10;			//remove o algarismo menos significativo da variavel 'temp'. Caso 'temp' tenha mais algarismos, continua o ciclo 
	}

	cout << "STRING  ? " << s << endl;
}
