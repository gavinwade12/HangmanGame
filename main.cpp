#include <iostream>
#include <string>

string GetWordToGuess();
bool CheckUserGuess(string);
void PrintCurrentString(string[]);

int main() {
	const int ALLOWED_INCORRECT_GUESSES = 8;
	int numOfGuesses = 0;
	bool complete = false;
	int correctGuesses = char[];
	string wordToGuess = GetWordToGuess();
	char userGuess;
	std::cout << "Welcome to the Hangman Game!" << endl;
	std::cout << "Getting your word ..." << endl;
	std::cout << "Got it! Make your first guess: ";
	std::cin >> userGuess;
	if (CheckUserGuess(userGuess)) {
		correctGuesses++;
		std::cout << "Good guess!" << endl;
	}
	else {
		std::cout << "Sorry, that letter isn't in this word." << endl;
	}

	numOfGuesses++;

	while (numOfGuesses <= ALLOWED_INCORRECT_GUESSES && !complete) {
		std::cout << "You've made " << numOfGuesses << " guesses. " << endl;
		std::cout << "You've made " << numOfGuesses - correctGuesses << " incorrect guesses." << endl;
		std::cout << ALLOWED_INCORRECT_GUESSES - (numOfGuesses - correctGuesses) << " left until you lose." << endl;
		std::cout << "Enter your "
		if (correctGuesses == wordToGuess.length())
			complete = true;
	}

}

string GetWordToGuess() {
	return;
}

bool CheckUserGuess(char guess, string wordToGuess) {
	if (wordToGuess.find(guess) != std::string::npos) {
		return true;
	}
	else
	{
		return false;
	}
}

void PrintCurrentString(string[]) {

}