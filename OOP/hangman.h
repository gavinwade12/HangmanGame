#include <string>
#include <vector>

class Hangman {
	public:
		Hangman(); 
		void GetWordToGuess();
		void CheckGuess(char userGuess);
		int GetNumberOfIncorrectGuesses();
		void PrintStatus();
		bool CheckForComplete();
		void PrintWord();
	private:
		bool CheckForRepeatGuess(char userGuess);
		std::string wordToGuess;
		std::vector<char> correctGuesses;
		std::vector<char> incorrectGuesses;
};