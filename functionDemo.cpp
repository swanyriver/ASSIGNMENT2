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
#include "myFunctions.h"

using namespace std;

void oneLetterAtATime(string my_str);

void formatName();

int main(){
	//problem one //oneLetterAtATime(swansonInput::getString("please enter a string: "));

	//problem two
	while(1)formatName();

}

//////////////////////////////////////
///PROBLEM TWO////////////////////////
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



