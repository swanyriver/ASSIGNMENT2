#include <string>
#include <list>
#include "myFunctions.h"
using namespace std;

bool swansonString::isALetter(char character){
	if( ( character >='a' && character <= 'z' )
	  ||( character >='A' && character <= 'Z' ) )return true;
	else return false;
}

bool swansonString::allLetters(string letterString){
	for ( int i = 0; i < letterString.length(); i++ ) {
		if(!isALetter(letterString.at(i))) return false;
	}
	return true;
}
bool swansonString::allLetters(string letterString, char permitedChars[], int arraySize){

	bool isAPermitedChar;

	for ( int i = 0; i < letterString.length(); i++ ) {
			isAPermitedChar = false;

			for(int j = 0; j < arraySize ; j++ ){
				if(letterString.at(i) == permitedChars[j]){
					isAPermitedChar = true;
				}
			}

			if( !( isALetter(letterString.at(i))
			       || isAPermitedChar ) ) {
				return false;
			}
	}
	return true;
}

void swansonString::seperateWords(string myString, list<string>& seperateWords){
	string currentWord;

	seperateWords.clear();

	int i=0;
	while(i < myString.length()
		  && !swansonString::isALetter( myString.at(i) ) ) i++; //find first letter;

	while(i<myString.length()){
		if( swansonString::isALetter( myString.at(i) ) ){
			currentWord+=myString.at(i);
			i++;
		}else{
			if( !currentWord.empty() ) seperateWords.push_back( currentWord );
			currentWord.clear();
			while(i < myString.length()
				  && !swansonString::isALetter( myString.at(i) ) ) i++; //find next letter;
		}
	}
	if( !currentWord.empty() ) seperateWords.push_back( currentWord );

}
