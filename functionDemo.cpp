/***********************************************************
* Author: Brandon Swanson
* Date Created: 06-29-2014
* Last Modification Date: 06-29-2014
* Filename: functionDemo.cpp
*
* Overview: This will be showcase of all of the various computational
* functions described in assignment 2
*
* Input:
*
* Output:
*
***********************************************************/

#include <iostream>
#include <string>

using namespace std;

bool isALetter(char character){
	if( ( character >='a' && character <= 'z' )
	  ||( character >='A' && character <= 'Z' ) )return true;
	else return false;
}

bool allLetters(string letterString){
	for ( int i = 0; i < letterString.length(); i++ ) {
		if(!isALetter(letterString.at(i))) return false;
	}
	return true;
}

void oneLetterAtATime(){
	//TODO add parameter, use safe string get
	cout << "GIVE ME A STRING";
	string my_str;
	cin >> my_str;

	if(my_str.empty()){  //TODO check for null pointer
		cout << endl << "there is something wrong with this string";
		return;
	}

	////////////////////////////
	///PRINT ONE CHAR AT A TIME/
	////////////////////////////
	cout << endl << "here it is forwards: ";
	for( int i = 0; i < my_str.length(); i++){
		cout << my_str.at(i) << ((i!=my_str.length()-1) ? "-" : "");
	}

	cout << endl << "here it is backwards: ";
	for( int i = my_str.length()-1; i >= 0; i--){
		cout << my_str.at(i) << ((i!=my_str.length()-1) ? "-" : "");
	}


	////////////////////////////
	///COUNT LETTERS////////////
	////////////////////////////

	int numLetters=0;
	for( int i = 0; i < my_str.length(); i++){
		if ( isALetter(my_str.at(i))) {
			numLetters++;
		}
	}
	cout << endl << "this string has " << numLetters << " letters" << endl;

	cout << "by a loop this string" << ( (allLetters(my_str) ? " is " : " is not ") )<< "all letters";
	cout << endl <<"by a length comparison this string"
		 << ( (my_str.length()==numLetters ? " is " : " is not ") )<< "all letters";


}




int main(){
	oneLetterAtATime();
}
