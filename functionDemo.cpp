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
#include <list>
#include <cstdlib>
#include "myFunctions.h"

using namespace std;

void oneLetterAtATime(string my_str);
void formatName();
void randomNumbers();
void compareStringsManually();
void betterRandom();

int main(){
	const int QUIT = 11;
	const int PLAY_ALL = 10;
	const int NUMBER_OF_SELECTIONS = 5;
	bool playAll = false;
	int selectionNumber;
	string prompt;

	cout << "welcome to assignment 2 exercise components,  I have a great variety of functionality to show you";

	do{
		if ( !playAll ) {
			cout << endl << "wich would you like to see now:"
				 << endl << "[1] o-n-e l-e-t-t-e-r a-t a t-i-m-e"
				 << endl << "[2] format a name"
				 << endl << "[3] Random Numbers"
				 << endl << "[4] Compare Strings"
				 << endl << "[5] Better Random Numbers"
				 << endl << "[10] Demonstrate All Functions"
				 << endl << "[11] Quit the program";

			selectionNumber = swansonInput::getInt("choose by number:",1,NUMBER_OF_SELECTIONS+2);
		}



		if( playAll && selectionNumber <= NUMBER_OF_SELECTIONS) selectionNumber++;
		if( playAll && selectionNumber > NUMBER_OF_SELECTIONS) selectionNumber = QUIT;
		if( selectionNumber == PLAY_ALL) {
					selectionNumber = 1;
					playAll = true;
		}

		do{
			switch ( selectionNumber ){
				case 1:
					prompt = "print more strings";
					oneLetterAtATime(swansonInput::getString("please enter a string: "));
					break;
				case 2:
					prompt = "format more names";
					formatName();
					break;
				case 3:
					prompt = "make more random numbers";
					randomNumbers();
					break;
				case 4:
					prompt = "compare more strings";
					compareStringsManually();
					break;
				case 5:
					prompt = "make more random numbers";
					betterRandom();
					break;
				default:
					selectionNumber = QUIT;
					break;
			}
		}while(selectionNumber != QUIT && swansonInput::yesNo(prompt));



	}while( selectionNumber != QUIT );

	cout << endl <<"thank you, come again soon" << endl;
}

//////////////////////////////////////////////
///PROBLEM FIVE/////BETTER RANDOM NUMBERS/////
//////////////////////////////////////////////
void betterRandom(){
	int number;
	number = swansonInput::getInt("lets test out stoi:");
	cout << "number returned:" << number << " times 5" << number * 5;
}

//////////////////////////////////////////////
///PROBLEM FOUR/////COMPARE STRING MANUALLY///
//////////////////////////////////////////////
bool compare(string stringOne, string stringTwo);

void compareStringsManually(){
	string stringInOne, stringInTwo;
	cout << endl << "this little peice of code is going to check two strings Letter-by-Letter";

	stringInOne = swansonInput::getString("Give me a string:");
	stringInTwo = swansonInput::getString("Ok, now give me another:");

	if( compare( stringInOne, stringInTwo ) ){
		cout << endl << "these strings are the same";
	}else{
		cout << endl << "these strings are different";
	}
}

bool compare(string stringOne, string stringTwo){
	if( stringOne.size() != stringTwo.size() ){
		return false;
	} else {
		for( int i = 0; i < stringOne.size(); i++ ) {
			if( stringOne.at( i ) != stringTwo.at( i ) ){
				return false;
			}
		}
	}
	return true;
}
//////////////////////////////////////
///PROBLEM THREE/////RANDOM NUMBERS///
//////////////////////////////////////

void randomNumbers(){

	cout << "here are some random numbers (0-99): ";
	for ( int i = 0; i < 10; i++ ){
		cout << rand() % 100 << " ";
	}
	cout << endl;
}

//////////////////////////////////////
///PROBLEM TWO////ARRANGE NAMES///////
//////////////////////////////////////

string getProperName();


void formatName(){
	//formatName local Variables
	list<string> namesSeperated;
	string fullNameUnformated;
	string firstName, middleName, lastName;
	char middleInitial;

	fullNameUnformated = getProperName();
	swansonString::seperateWords(fullNameUnformated, namesSeperated);

	while( !( namesSeperated.size() == 2 || namesSeperated.size() == 3 ) ){
		cout << endl << "It seems you have given me too few or too many names";
		fullNameUnformated = getProperName();
		swansonString::seperateWords(fullNameUnformated, namesSeperated);
	}

	if( namesSeperated.size() == 2){
		firstName = namesSeperated.front();
		lastName = namesSeperated.back();

		cout << endl << lastName << " " << firstName;

	} else if ( namesSeperated.size() == 3){
		firstName = namesSeperated.front();
		namesSeperated.pop_front();
		middleName = namesSeperated.front();
		namesSeperated.pop_front();
		lastName = namesSeperated.front();
		namesSeperated.pop_front();

		middleInitial=middleName.at(0);

		cout << endl << lastName << " "  << middleInitial << ". "<< firstName;
	}



}

string getProperName(){
	char permitedChars[] = {' ','.'};
	string name;

	name = swansonInput::getString("Please tell me your full name: ");

	while(!swansonString::allLetters(name,permitedChars,2)){
		cout << "Im sorry, try to keep it to only letters";
		name = swansonInput::getString("Please tell me your full name: ");
	}

	return name;

}

//////////////////////////////////////
///PROBLEM ONE////////////////////////
//////////////////////////////////////

void oneLetterAtATime(string my_str){

	/********************************************************
	******Function Paramater-ized for ease of encapsulation
	********************************************************
	//TODO add parameter, use safe string get // 6/29 13:15
	cout << "GIVE ME A STRING";
	string my_str;
	//cin >> my_str; //changed to getLine 6/29 13:00 as per step g.
	//getline(cin,my_str); //allowed for multiple word input 6/29 13:10
	 **********************************************************/

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
		cout << my_str.at(i) << ((i!=0) ? "-" : "");
	}


	////////////////////////////
	///COUNT LETTERS////////////
	////////////////////////////

	int numLetters=0;
	for( int i = 0; i < my_str.length(); i++){
		if ( swansonString::isALetter(my_str.at(i))) {
			numLetters++;
		}
	}
	cout << endl << "this string has " << numLetters << " letters" << endl;

	cout << "by a loop this string" << ( (swansonString::allLetters(my_str) ? " is " : " is not ") )<< "all letters";
	cout << endl <<"by a length comparison this string"
		 << ( (my_str.length()==numLetters ? " is " : " is not ") )<< "all letters";


}



