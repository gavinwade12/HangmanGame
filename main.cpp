#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>

std::string GetWordToGuess();
bool CheckUserGuess(char userGuess, std::string wordToGuess);
void PrintCurrentString(std::string wordToGuess, std::string correctGuesses);

int main() {
	const int ALLOWED_INCORRECT_GUESSES = 8;
	int numOfGuesses = 0;
	bool complete = false;
	std::string wordToGuess = GetWordToGuess();
	std::transform(wordToGuess.begin(), wordToGuess.end(), wordToGuess.begin(), ::tolower);
	std::string correctGuesses = "";
	char userGuess;
	std::cout << "Welcome to the Hangman Game!" << std::endl;
	std::cout << "Getting your word ..." << std::endl;
	std::cout << "Got it! The word is " << wordToGuess.length() << " letters long. Make your first guess: ";
	std::cin >> userGuess;
	userGuess = tolower(userGuess);
	if (CheckUserGuess(userGuess, wordToGuess)) {
		correctGuesses += userGuess;
		std::cout << "Good guess!" << std::endl;
	}
	else
		std::cout << "Sorry, that letter isn't in this word." << std::endl;

	numOfGuesses++;

	while ((numOfGuesses - correctGuesses.length()) < ALLOWED_INCORRECT_GUESSES && !complete) {
		std::cout << "You've made " << numOfGuesses << " guesses. " << std::endl;
		std::cout << "You've made " << numOfGuesses - correctGuesses.length() << " incorrect guesses." << std::endl;
		std::cout << ALLOWED_INCORRECT_GUESSES - (numOfGuesses - correctGuesses.length()) << " left until you lose." << std::endl;
		std::cout << "Enter your guess: ";
		std::cin >> userGuess;
		userGuess = tolower(userGuess);
		numOfGuesses++;
		if (CheckUserGuess(userGuess, wordToGuess))
			correctGuesses += userGuess;

		PrintCurrentString(wordToGuess, correctGuesses);
		if (correctGuesses.length() == wordToGuess.length()) {
			complete = true;
			std::cout << "You win!" << std::endl;
		}
	}

	if (!complete)
		std::cout << "Sorry, you lose. The word was: " << wordToGuess << std::endl;

	return 0;

}

std::string GetWordToGuess() {
	std::string word;
	std::ifstream myFile;
	myFile.open("randomwords.txt");
	int randomNumber = rand() % 100;
	for (int i = 0; i < randomNumber; i++) {
		myFile >> word;
	}
	return word;
}

bool CheckUserGuess(char guess, std::string wordToGuess) {
	if (wordToGuess.find(guess) != std::string::npos)
		return true;
	else
		return false;
}

void PrintCurrentString(std::string wordToGuess, std::string correctGuesses) {
	bool found = false;
	std::cout << "Here is how you're doing so far: ";
	for (int i = 0; i < wordToGuess.length(); i++) {
		for (int j = 0; j < correctGuesses.length(); j++) {
			if (wordToGuess[i] == correctGuesses[j]) {
				found = true;
			}
		}
		if (found)
			std::cout << wordToGuess[i];
		else
			std::cout << " _ ";

		found = false;
	}
	std::cout << std::endl;
}