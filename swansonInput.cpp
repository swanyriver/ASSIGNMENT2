#include <string>
#include <iostream>
#include "myFunctions.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

string swansonInput::getString(string prompt){

	string str_rtrn="";

	//request input
	cout << endl << prompt;

	///Clearing errors and NewLine char
	cin.clear();
	if(cin.peek()=='\n'){
		cin.ignore(1000, '\n');
	}

	//grabEntireLine
	getline(cin, str_rtrn);

	return str_rtrn;

}
