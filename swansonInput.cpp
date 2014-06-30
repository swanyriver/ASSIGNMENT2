#include <string>
#include <iostream>
#include "myFunctions.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

static const int MAX_ATTEMPTS = 6;

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

int swansonInput::getInt(string prompt){
	int int_rtrn;
	int attempts = 0;
	string parse_string;
	string::size_type size;

	parse_string = getString(prompt);

	while( !swansonString::allNumbers(parse_string) || parse_string.empty()){
		attempts++;
		if( attempts > MAX_ATTEMPTS ) return 0;

		cout << "lets try to restrain ourselves to only whole numbers";
		parse_string = getString(prompt);
	}

	int_rtrn = std::stoi(parse_string,&size);


	return int_rtrn;

}



bool swansonInput::yesNo(string prompt){
	string yesNoStr;

	for(int i=0; i < MAX_ATTEMPTS; i++){ //give them X trys at succsesful input
		yesNoStr = swansonInput::getString(prompt+" (y/n)?:");
		yesNoStr = swansonString::lowerCase(yesNoStr);

		if ( yesNoStr == "y" ||
			yesNoStr == "yes") return true;
		else if ( yesNoStr == "n" ||
				yesNoStr == "no") return false;
	}
	return false; //give up

}
