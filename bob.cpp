#include <iostream>
#include <string>

//function definition - this function will show up later
char GetLetterToGuess();

//main function
int main() {
	//variables of type char
	char guess;
	char toGuess = GetLetterToGuess(); //assigns value return by GetLetterToGuess function to toGuess
	//outputs to the screen
	std::cout << "Hey bob." << std::endl;
	std::cout << "I just picked a letter from the alphabet. What is it? ";
	std::cin >> guess;
	if (guess == toGuess) {
		std::cout << "Nice guess!" << std::endl;
	}
	else {
		std::cout << "Sorry, you're wrong. The letter was: " << toGuess << std::endl;;
	}
	return 0;
}

char GetLetterToGuess() {
	return 'a';
}