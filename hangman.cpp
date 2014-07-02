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

void initializeVars ();
string playerOnePickWord ();
string playerTwoGuess ();
void processGuess ( string guessString );
void printResults ();
void clearScreen ();

//const int MAX_GUESSES = 10;
const int MAX_WORD_LENGTH = 12;
const int LENGTH_OF_ALPHABET = 26;
const int CLEAR_SCREEN_CHAR_NUM = 6000;

string SecretWord;
int maxGuesses;
char lettersRevealed[LENGTH_OF_ALPHABET];
char lettersInSecretWord[LENGTH_OF_ALPHABET];
string guessesMade[LENGTH_OF_ALPHABET];
int numLettersRevealed;
int numGuessesMade;
int numLettersInWord; //distinct letters

int main () {

   do { //restart game
      initializeVars();

      clearScreen();

      do { // make guesses
         string guessString = playerTwoGuess();
         guessesMade[numGuessesMade] = guessString;
         numGuessesMade++;

         processGuess(guessString);

         if ( !(guessString == SecretWord
               || numLettersRevealed == numLettersInWord) ) {
            printResults();
         }

         /////debug string////////
         /*cout << numGuessesMade << " " << MAX_GUESSES
          << "  " << numLettersRevealed << "/" << numLettersInWord
          << " " << SecretWord << "  " << guessesMade[numGuessesMade-1]
          << endl;*/
         ///////debug string
      } while ( numGuessesMade < maxGuesses
            && numLettersRevealed < numLettersInWord
            && guessesMade[numGuessesMade - 1] != SecretWord );

      if ( guessesMade[numGuessesMade - 1] == SecretWord
            || numLettersRevealed == numLettersInWord ) {
         cout << YOU_WIN;
      } else {
         cout << YOU_LOSE;
      }

   } while ( swansonInput::yesNo( PLAY_AGAIN_STR) );

   cout << endl << GOODBYE_STR << endl;

   return 0;
}

void initializeVars () {
   SecretWord = playerOnePickWord();

   maxGuesses = swansonInput::getInt(MAX_GUESSES_STR, 1, LENGTH_OF_ALPHABET);

   numLettersRevealed = 0;
   numGuessesMade = 0;

   numLettersRevealed = 0;
   for ( int i = 0 ; i < SecretWord.size() ; i++ ) { //set lettersInSecretWord[];
      if ( !swansonUtil::contains(SecretWord.at(i), lettersInSecretWord,
            numLettersInWord) ) {
         lettersInSecretWord[numLettersInWord] = SecretWord.at(i);
         numLettersInWord++;
      }
   }

}
string playerOnePickWord () {

   string secretString;
   secretString = swansonInput::getOneWord(ENTER_WORD_STR);

   while ( secretString.size() > MAX_WORD_LENGTH ) {
      cout << endl << TOO_LONG;
      secretString = swansonInput::getOneWord(ENTER_WORD_STR);
   }

   secretString = swansonString::lowerCase(secretString);
   return secretString;
}

void clearScreen () {
   char randChar;
   for ( int i = 0 ; i < CLEAR_SCREEN_CHAR_NUM ; i++ ) {
      randChar = swansonUtil::randomInRange('A', 'Z');
      cout << randChar;
   }

   cout << endl << endl;
}

string playerTwoGuess () {
   string guessString;
   bool retry;

   cout << GUESS_INSTR_STR;
   cout << endl << NUM_GUESSES << maxGuesses - numGuessesMade;

   do {
      retry = false;
      do {
         if ( retry )
            cout << ENTERED_BEFORE;
         guessString = swansonInput::getOneWord(GUESS_PROMPT);
         guessString = swansonString::lowerCase(guessString);
         retry = true;
      } while ( swansonUtil::contains(guessString, guessesMade, numGuessesMade) );
   } while ( guessString.size() > 1
         && !swansonInput::yesNo( GUESS_CHECK + guessString + "\n") );

   return guessString;

}

void processGuess ( string guessString ) {

   if ( guessString.size() == 1 ) {
      //check character
      if ( swansonUtil::contains(guessString.at(0), lettersInSecretWord,
            numLettersInWord) ) {
         lettersRevealed[numLettersRevealed] = guessString.at(0);
         numLettersRevealed++;
      }
   }

}

void printResults () {
   cout << endl << STILL_WRONG << endl << STRING_HINT << endl;
   for ( int i = 0 ; i < SecretWord.size() ; i++ ) {
      cout << " ";
      char cursorChar = SecretWord.at(i);
      if ( swansonUtil::contains(cursorChar, lettersRevealed,
            numLettersRevealed) ) {
         cout << cursorChar;
      } else
         cout << "-";
   }
}
