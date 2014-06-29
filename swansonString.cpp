#include <iostream>
#include "myFunctions.h"
using std::string;


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
