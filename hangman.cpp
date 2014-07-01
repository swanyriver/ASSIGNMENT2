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
void processGuess(string guessString);
void printResults();

const int MAX_GUESSES = 10;
const int MAX_WORD_LENGTH = 12;

string SecretWord;
char lettersRevealed[26];
char lettersInSecretWord[MAX_WORD_LENGTH];
string guessesMade[MAX_GUESSES];
int numLettersRevealed;
int numGuessesMade;
int numLettersInWord; //distinct letters

int main(){

	do{ //restart game
		initializeVars();

		do{ // make guesses
			string guessString = playerTwoGuess();
			guessesMade[numGuessesMade] = guessString;
			numGuessesMade++;

			processGuess(guessString);

			if( !( guessString == SecretWord
				|| numLettersRevealed == numLettersInWord ) ){
				printResults();
			}

			/////debug string////////
			/*cout << numGuessesMade << " " << MAX_GUESSES
				<< "  " << numLettersRevealed << "/" << numLettersInWord
				<< " " << SecretWord << "  " << guessesMade[numGuessesMade-1] << endl;*/
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
	//numLettersInWord = SecretWord.size(); //no good

	numLettersRevealed = 0;
	for (int i = 0; i < SecretWord.size(); i++) {
		if( !swansonUtil::contains( SecretWord.at(i) , lettersInSecretWord , numLettersInWord) ) {
			lettersInSecretWord[numLettersInWord] = SecretWord.at(i);
			numLettersInWord++;
		}
	}

}
string playerOnePickWord(){

	string secretString;
	secretString = swansonInput::getOneWord(ENTER_WORD_STR);
	secretString = swansonString::lowerCase(secretString);
	return secretString;
}
string playerTwoGuess(){
	string guessString;
	bool retry = false;

	cout << GUESS_INSTR_STR;
	cout << endl << NUM_GUESSES << MAX_GUESSES-numGuessesMade;

	do {
		if( retry ) cout << ENTERED_BEFORE;
		guessString = swansonInput::getOneWord(GUESS_PROMPT);
		guessString = swansonString::lowerCase(guessString);
		retry=true;
	} while ( swansonUtil::contains(guessString , guessesMade , numGuessesMade));

	return guessString;

}

void processGuess( string guessString ){

	if( guessString.size() == 1 ){
		//check character
		if( swansonUtil::contains(guessString.at(0), lettersInSecretWord, numLettersInWord)){
			lettersRevealed[numLettersRevealed] = guessString.at(0);
			numLettersRevealed++;
		}
	}

}

void printResults(){
	cout << endl << STILL_WRONG << endl
			<< STRING_HINT << endl;
	for ( int i = 0; i < SecretWord.size() ; i++ ){
		cout << " ";
		char cursorChar = SecretWord.at(i);
		if(swansonUtil::contains( cursorChar , lettersRevealed , numLettersRevealed ) ){
			cout << cursorChar;
		} else cout << "-";
	}
}
