#include "func10.h"

using namespace std;

int rand_int(int a, int b)
{
	int randN;
	srand((unsigned int)time(NULL));
	randN = rand() % (b - a + 1) + a;
	return randN;
}

int string_to_int(std::string s)
{
	int sum = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		sum += (s[i] - 48)* (int)pow(10, s.length() - i - 1);
	}
	return sum;
}

std::string int_to_string(int n)
{
	int temp, rem;
	temp = n;
	std::string s;

	if (n == 0) s = (char)(48);
	while (temp > 0)
	{
		rem = temp % 10;
		s = (char)(rem + 48) + s;
		temp = temp / 10;
	}

	return s;
}

std::string get_sentence(std::string filename)
{
	std::string line;
	unsigned int nlines = 0, exp = 0;
	std::ifstream fs;

	fs.open(filename, std::ifstream::in);									//tenta abrir ficheiro 
	if (!fs.is_open()){
		std::cout << "ERROR: File not found!" << std::endl;	//se nao consegue abrir ficheiro e' porque nao o encontrou
		return "";
	}
	else{
		getline(fs, line);											//extrai a primeira linha para ver se contem o numero de linhas  
		nlines = string_to_int(line);
		srand((unsigned int)time(NULL));
		int randN = rand() % nlines + 1;							//escolhe uma linha aleatoriamente
		for (int i = 0; i < randN; i++) getline(fs, line);			//extrai linhas ate chegar a selecionada por 'rand()'
		return line;
	}
	fs.close();														//fecha ficheiro 
}

std::string string_to_upper(std::string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}

std::string unhide_letters(std::string s, std::vector<char> letters)
{
	std::string c = string_to_upper(s);
	bool presente;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		presente = 0;
		if (c[i] != ' ')
		{
			for (unsigned int j = 0; j < letters.size(); j++)
			{
				if (letters[j] == c[i]) { presente = 1; break; }
			}
			if (presente == 0) s[i] = '*';
		}
	}
	return s;
}

void show_vector_char(std::vector<char> v)
{
	std::cout << "[ ";
	for (unsigned int i = 0; i < v.size(); i++)		//corre o vector para exibir na consola as letras recolhidas
	{
		std::cout << v[i] << " ";
	}
	std::cout << "]" << std::endl;
}

bool show_file(std::string filename)
{
	std::ifstream fs;
	std::string line;
	fs.open(filename, std::ifstream::in);							//tenta abrir ficheiro 
	if (!fs.is_open()) return 0;									//se não consegue abrir ficheiro é porque não o encontrou 
	else{
		while (getline(fs, line)) std::cout << line << std::endl;	//enquanto nao chegar ao fim do ficheiro extrai linhas e mostra na consola
	}
	fs.close();
	return 1;
}

unsigned int count_letters(std::string s)			//counts the number of letters in s(used by calculate_score()); other characters are not counted;
{
	unsigned int n = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ') n++;
	}
	return n;
}


unsigned int count_diff_letters(std::string s)		//counts the number of different letters in s(used by calculate_score())
{
	vector <char> letters;
	bool exists;
	int count = 0;
	s = string_to_upper(s);
	//cout << "s.size = " << s.size() << endl;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		exists = 0;
		//cout << "i = " << i << endl;
		for (unsigned int j = 0; j < letters.size(); j++)
		{
			if (s[i] == letters[j]) { exists = 1; break; }
		}
		if (exists == 0)
		{
			letters.push_back(s[i]);
			count++;
		}
	}
	return count;
}

int trials;

unsigned int calculate_score(std::string s, unsigned int tnm, unsigned int t) //calculates the score obtain by a player that has guessed the word / sentence
{
	/*score = 100000 * (1 + NDL / TNL) / (T * (1 + 0.1*TNM / MNT))
	rounded to the nearest integer, where
	o TNL = total no. of letters in the word/sentence
	o NDL = no. of different letters in the word/sentence
	o TNM = no. of missed trials (to guess a letter)
	o MNT = maximum no. of trials that are given to the player
	o T = total time, in seconds, that the player took to guess the word/sentence*/

	int score = (int)round(100000 * (1 + count_diff_letters(s) / count_letters(s)) / (t * (1 + 0.1*tnm / trials)));
	return score;
}

vector<Score_info> get_best_scores(std::string filename)		//returns a vector of structs containing the information about the best players, contained in file filename.
{
	vector<Score_info> best_scores;
	std::ifstream file_best;
	file_best.open(filename, std::ifstream::in);
	if (file_best.is_open()){
		Score_info player;
		string score;
		while (getline(file_best, player.name))
		{
			getline(file_best, score);
			player.score = string_to_int(score);
			//file_best >> (string) player.name >> player.score;
			best_scores.push_back(player);
		}
		file_best.close();
	}
	return best_scores;
}

void show_best_scores(const vector<Score_info> &best_scores)	//shows the contents of best_scores on the screen.
{
	string score;
	cout << "Best players until now:" << endl;
	for (unsigned int i = 0; i < best_scores.size(); i++)
	{
		score = int_to_string(best_scores[i].score);
		while (score.size() < 5) score = ' ' + score;
		cout << score << " - " << best_scores[i].name << endl;
	}
	cout << endl;
}

void update_best_scores(vector<Score_info>& best_scores, const Score_info &si)//updates the contents of best_scores, by adding to it the struct si, and sorts the vector so that the players are maintained in descending order of their scores(field score of Score_info).
{
	if (best_scores.size() == 0)
		best_scores.push_back(si);
	else{
		bool updated = 0;
		for (unsigned int i = 0; i < best_scores.size(); i++)
		{
			if (si.score > best_scores[i].score)
			{
				best_scores.insert(best_scores.begin() + i, si);
				updated = 1;
				break;
			}
		}
		if (!updated) best_scores.push_back(si);
	}
}


void save_best_scores(std::string filename, const vector<Score_info> &best_scores, int n_best)	//stores in text file named filename the n_best first elements of vector best_scores
{
	std::ofstream file_best;
	file_best.open(filename, std::ofstream::out);
	if (file_best.is_open()){
		if (n_best > best_scores.size()) n_best = best_scores.size();
		for (int i = 0; i < n_best; i++)
		{
			file_best << best_scores[i].name << endl << best_scores[i].score << endl;
		}
		file_best.close();
	}
}


bool input(string s, vector <char> &v)
{
	int c;
	s = string_to_upper(s);
	bool cont = 0, present = 0;
	do {
		cout << "BET (LETTER)  ? ";
		c = _getch();
		cout << (char)c << endl;
		if ((c >= 'a') && (c <= 'z')) c = c + 'A' - 'a';	//se for lower case, transforma em uppercase
		if ((c >= 'A') && (c <= 'Z'))						//se for letra (ja esta em uppercase) corre o vector para ver se já existe
		{
			cont = 0;
			for (unsigned int i = 0; i < v.size(); i++)
			{
				if (v[i] == (char)c) { cont = 1; break; }
			}
			if (cont == 0) v.push_back((char)c);	//se não existe, insere a letra no vector
		}
		else cont = 1;
	} while (cont == 1);


	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (c == s[i]) {
			present = 1;
			break;
		}
	}
	return present;
}