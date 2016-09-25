#include "hangman.h"
#include <iostream>

int main() {
	const int ALLOWED_INCORRECT_GUESSES = 8;
	char userGuess;
	int incorrectGuesses = 0;

	std::cout << "Welcome to the Hangman Game!" << std::endl << std::endl;
	Hangman myHangman;
	myHangman.GetWordToGuess();

	while (!myHangman.CheckForComplete() 
	  && myHangman.GetNumberOfIncorrectGuesses() <= ALLOWED_INCORRECT_GUESSES) {
		std::cout << "Enter your guess: ";
		std::cin >> userGuess;
		myHangman.CheckGuess(tolower(userGuess));
		myHangman.PrintStatus();

		incorrectGuesses = myHangman.GetNumberOfIncorrectGuesses();

		std::cout << std::endl << "You've made " << incorrectGuesses << 
			" incorrect guesses." << std::endl;
		std::cout << "You will lose with " << 
			ALLOWED_INCORRECT_GUESSES + 1 - incorrectGuesses <<
			" more incorrect guesses." << std::endl << std::endl;
	}

	if (myHangman.CheckForComplete())
		std::cout << "You win!" << std::endl;
	else {
		std::cout << "Sorry, you lost. The word was: ";
		myHangman.PrintWord();
		std::cout << std::endl;
	}

	return 0;
}