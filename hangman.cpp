/***********************************************************
* Author: Brandon Swanson
* Date Created: 06-30-2014
* Last Modification Date: 06-30-2014
* Filename: hangman.cpp
*
* Overview: A word guessing game
*
* Input: A secret word, letter guesses
*
* Output: correctly guess letters
*
***********************************************************/

#include "myFunctions.h"
#include "hangmanStrings.h"
#include <iostream>
#include <string>

using namespace std;

void initializeVars();
string playerOnePickWord();
string playerTwoGuess();

const int MAX_GUESSES = 10;
const int MAX_WORD_LENGTH = 12;

string SecretWord;
char lettersRevealed[26];
string guessesMade[MAX_GUESSES];
int numLettersRevealed;
int numGuessesMade;
int numLettersInWord;

int main(){

	do{
		initializeVars();

		do{
			guessesMade[numGuessesMade] = playerTwoGuess();
			numGuessesMade++;

			/////debug string////////
			cout << numGuessesMade << " " << MAX_GUESSES
				<< "  " << numLettersRevealed << "/" << numLettersInWord
				<< " " << SecretWord << "  " << guessesMade[numGuessesMade-1] << endl;
			///////debug string

		}while( numGuessesMade < MAX_GUESSES
				&& numLettersRevealed < numLettersInWord
				&& guessesMade[numGuessesMade-1] != SecretWord );



		if( guessesMade[numGuessesMade-1] == SecretWord
				|| numLettersRevealed == numLettersInWord ) {
			cout << "you win";
		}

	}while ( swansonInput::yesNo( PLAY_AGAIN_STR ) );

	cout << endl << GOODBYE_STR << endl;

	return 0;
}

void initializeVars(){
	SecretWord = playerOnePickWord();
	//lettersRevealed = char[26]; //leave it full, just only search numLettersRevealed
	//string guessesMade[MAX_GUESSES]; //leave it full, just only search numGuessesMade
	numLettersRevealed = 0;
	numGuessesMade = 0;
	numLettersInWord = SecretWord.size();
}
string playerOnePickWord(){

	return swansonInput::getOneWord(ENTER_WORD_STR);

}
string playerTwoGuess(){

	return "nothing";

}
