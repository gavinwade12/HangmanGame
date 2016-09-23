#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

string GetWordToGuess();
string GetDistinctWordToGuess(string wordToGuess);
bool CheckUserGuess(char userGuess, string wordToGuess);
void PrintCurrentString(string wordToGuess, string correctGuesses);

int main() {
	const int ALLOWED_INCORRECT_GUESSES = 8;
	int numOfGuesses = 0;
	bool complete = false;
	string wordToGuess = GetWordToGuess();
	string wordToGuessDistinct = GetDistinctWordToGuess(wordToGuess);
	transform(wordToGuess.begin(), wordToGuess.end(), wordToGuess.begin(), ::tolower);
	int numOfCorrectGuesses = 0;
	string correctGuesses = "";
	char userGuess;
	cout << "Welcome to the Hangman Game!" << endl;
	cout << "Getting your word ..." << endl;
	cout << "Got it! The word is " << wordToGuess.length() << " letters long. Make your first guess: ";
	cin >> userGuess;
	userGuess = tolower(userGuess);
	if (CheckUserGuess(userGuess, wordToGuess)) {
		if (correctGuesses.find(userGuess) == string::npos)
		{
			correctGuesses += userGuess;
		}
		numOfCorrectGuesses++;
		cout << "Good guess!" << endl;
	}
	else {
		cout << "Sorry, that letter isn't in this word." << endl;
	}
	PrintCurrentString(wordToGuess, correctGuesses);
	numOfGuesses++;

	while (numOfGuesses - numOfCorrectGuesses <= ALLOWED_INCORRECT_GUESSES && !complete) {
		cout << "You've made " << numOfGuesses << " guesses. " << endl;
		cout << "You've made " << (numOfGuesses - correctGuesses.length()) << " incorrect guesses." << endl;
		cout << (ALLOWED_INCORRECT_GUESSES - (numOfGuesses - numOfCorrectGuesses) + 1) << " left until you lose." << endl;
		cout << "Enter your guess: ";
		cin >> userGuess;
		userGuess = tolower(userGuess);
		if (CheckUserGuess(userGuess, wordToGuess)) {
			if (correctGuesses.find(userGuess) == string::npos)
			{
				correctGuesses += userGuess;
			}
			numOfCorrectGuesses++;
		}
		PrintCurrentString(wordToGuess, correctGuesses);
		if (correctGuesses.length() == wordToGuessDistinct.length()) {
			complete = true;
			cout << "You win!" << endl;
		}
		numOfGuesses++;
	}

	if (numOfGuesses - numOfCorrectGuesses > ALLOWED_INCORRECT_GUESSES && !complete) {
		cout << "Sorry, you lose. The word was: " << wordToGuess << "." << endl;
	}

	return 0;
}

string GetWordToGuess() {
	string word;
	ifstream myFile;
	myFile.open("randomwords.txt");
	srand(time(NULL));
	int randomNumber = rand() % 100;
	for (int i = 0; i < randomNumber; i++) {
		myFile >> word;
	}
	return word;
}

string GetDistinctWordToGuess(string wordToGuess) {
	string distinct = "";
	for (int i = 0; i < wordToGuess.length(); i++)
	{
		if (distinct.find(wordToGuess[i]) == string::npos)
		{
			distinct += wordToGuess[i];
		}
	}
	return distinct;
}

bool CheckUserGuess(char guess, string wordToGuess) {
	if (wordToGuess.find(guess) != string::npos) {
		return true;
	}
	else
	{
		return false;
	}
}

void PrintCurrentString(string wordToGuess, string correctGuesses) {
	bool found = false;
	cout << "Here is how you're doing so far: ";
	for (int i = 0; i < wordToGuess.length(); i++) {
		for (int j = 0; j < correctGuesses.length(); j++) {
			if (wordToGuess[i] == correctGuesses[j]) {
				found = true;
			}
		}
		if (found) {
			cout << wordToGuess[i];
		}
		else {
			cout << " _ ";
		}
		found = false;
	}
	cout << endl;
}