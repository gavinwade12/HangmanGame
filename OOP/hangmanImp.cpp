#include "hangman.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <typeinfo>

Hangman::Hangman() {
	wordToGuess = "";
}

void Hangman::GetWordToGuess() {
	std::cout << "Getting you a word.." << std::endl;
	std::string word;
	std::ifstream myFile;
	myFile.open("randomwords.txt");
	srand(time(NULL));
	int randomNumber = rand() % 100;
	for (int i = 0; i < randomNumber; i++) {
		if (myFile.good() && !myFile.eof())
			myFile >> word;
	}
	myFile.close();
	std::cout << "Got it! It's " << word.length() << " characters long." << std::endl;
	wordToGuess = word;
	correctGuesses.resize(wordToGuess.length());
}

void Hangman::CheckGuess(char userGuess) {
	bool found = false;
	if (CheckForRepeatGuess(userGuess)) {
		std::cout << "You've already guessed that." << std::endl;
		return;
	}

	for (int i = 0; i < wordToGuess.length(); i++) {
		if (wordToGuess[i] == userGuess) {
			correctGuesses[i] = userGuess;
			found = true;
		}
	}
	if (!found) {
		incorrectGuesses.push_back(userGuess);
		std::cout << "Sorry, that wasn't correct." << std::endl;
	}
	else
		std::cout << "Nice guess." << std::endl;
}

int Hangman::GetNumberOfIncorrectGuesses() {
	return incorrectGuesses.size();
}

void Hangman::PrintStatus() {
	std::cout << "Here is how you're doing: ";
	for (int i = 0; i < wordToGuess.length(); i++) {
		if (wordToGuess[i] == correctGuesses[i])
			std::cout << wordToGuess[i];
		else
			std::cout << " _ ";
	}
	std::cout << std::endl << "Incorrect guesses: [ ";
	for (int i = 0; i < incorrectGuesses.size(); i++) {
		std::cout << incorrectGuesses[i];
		if (i != incorrectGuesses.size() - 1)
			std::cout << ", ";
	}
	std::cout << " ]" << std::endl;
}

bool Hangman::CheckForComplete() {
	for (int i = 0; i < wordToGuess.length(); i++)
		if (wordToGuess[i] != correctGuesses[i])
			return false;
	return true;

}

void Hangman::PrintWord() {
	std::cout << wordToGuess;
}

bool Hangman::CheckForRepeatGuess(char userGuess) {
	for (int i = 0; i < correctGuesses.size(); i++) {
		if (correctGuesses[i] == userGuess)
			return true;
	}

	for (int i = 0; i < incorrectGuesses.size(); i++) {
		if (incorrectGuesses[i] == userGuess)
			return true;
	}
	return false;
}