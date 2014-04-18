#include "func10.h"

using namespace std; 

void main()
{
	vector<char> letters;
	string word = get_sentence("sentences.txt");
	int min, max;
	if (word.length() > 7) min = 7;
	else min = word.length();
	if (word.length() * 2 > 9) max = 9;
	else max = word.length() * 2;
	trials = rand_int(min, max);
	int init_trials = trials;
	bool winner = 0;

	cout << "HANGMAN" << endl << endl;
	cout << "Try to guess the word / sentence" << endl;
	cout << "Each letter is represented by an '*'" << endl;
	cout << "You have " << trials << " trials" << endl << endl;

	vector<Score_info> best_scores = get_best_scores("best.txt");
	if (best_scores.size() != 0) show_best_scores(best_scores);

	Score_info player;
	cout << "Player name ? ";
	getline(cin, player.name);
	cout << endl;

	unsigned int time_begin = (unsigned int)time(0);

	while (trials > 0)
	{
		cout << "PREVIOUS BETS : ";
		show_vector_char(letters);
		cout << "KNOWN LETTERS : " << unhide_letters(word, letters) << endl;
		//verificar se ainda há asteriscos
		if (unhide_letters(word, letters).find("*") == std::string::npos)
		{
			winner = 1;
			break;
		}
		if (!input(word, letters)){
			trials--;
		}
		if (trials != init_trials) show_file("fig" + int_to_string(trials + 1) + ".txt");
	}

	unsigned int time_end = (unsigned int)time(0);
	int elapsed_time = time_end - time_begin;
	if (winner){
		cout << endl << "YOU ARE A WINNER. CONGRATULATIONS !" << endl;
		player.score = calculate_score(word, init_trials - trials, elapsed_time);
		cout << endl << "You took " << elapsed_time << " seconds and have obtained " << player.score << " points" << endl << endl;
		update_best_scores(best_scores, player);
		show_best_scores(best_scores);
		save_best_scores("best.txt", best_scores, 10);
	}
	else{
		cout << endl << "The word / sentence was : " << word << endl << endl;
		cout << "YOU HAVE LOST ! WE ARE GOING TO CALL THE UNDERTAKERS :-(" << endl;
	}
	_getch();
}