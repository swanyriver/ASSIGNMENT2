#include <string>
#include <iostream>
#include "myFunctions.h"
#include <climits>
#include <cstdlib> 
#include <cfloat>
#include <errno.h>

#define RETRY_GET_WORD 	"Lets try that again"
#define THIS_WORD	 	"Is this the word you wanted to input"

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

string swansonInput::getOneWord(string prompt){
	string candaditeWord;
	bool retry = false;

	do{
		if( retry ){
			cout << RETRY_GET_WORD;
		}

		candaditeWord = swansonInput::getString(prompt);

		list<string> seperatedWords;
		swansonString::seperateWords(candaditeWord , seperatedWords );

		string allLetterWord;
		string nextWord;
		while( !seperatedWords.empty() && allLetterWord.empty() ){

			nextWord = seperatedWords.front();
			seperatedWords.pop_front();

			if( swansonString::allLetters( nextWord ) ){
				allLetterWord = nextWord;
			} else {
				for (int i = 0; i < nextWord.size() ; i++ )
					if( swansonString::isALetter(nextWord.at(i) ) )
						allLetterWord+=nextWord.at(i);
			}
		}

		candaditeWord = allLetterWord;

		if( !candaditeWord.empty() ){
			cout << endl << candaditeWord << endl;
			if( !swansonInput::yesNo(THIS_WORD) ){
				candaditeWord.clear();
			}
		}

		retry = true;

	}while( candaditeWord.empty() );

	return candaditeWord;
}

int swansonInput::getInt(string prompt){
	return getInt(prompt, INT_MIN, INT_MAX);
}

int swansonInput::getInt(string prompt, int rangeMax, int rangeMin){
	return static_cast<int>(getLong(prompt, rangeMax, rangeMin));
}

long int swansonInput::getLong(string prompt){
	return getLong( prompt, LONG_MIN, LONG_MAX);

}
long int swansonInput::getLong(string prompt, long int rangeMin, long int rangeMax){
	long int int_rtrn;
	int attempts = 0;
	string parse_string;
	bool firstTimeThrough = true;

	do {
		if(!firstTimeThrough){
			cout << "Please keep the input within these bounds ["
				 << rangeMin << " - " << rangeMax << "]";
		}
		firstTimeThrough=false;
		parse_string = swansonInput::getString(prompt);

		//TODO use errno or HUGE_VAL to check for overflow
		//TODO change to strtol
		while( !swansonString::allNumbers(parse_string) || parse_string.empty()){
			attempts++;
			if( attempts > MAX_ATTEMPTS ) return 0;

			cout << "lets try to restrain ourselves to only whole numbers";
			parse_string = swansonInput::getString(prompt);
		}


		//int_rtrn = atol(parse_string.c_str());  //changed to strtol for overflow erno
		int_rtrn = strtol(parse_string.c_str() , NULL, 0);

		//if (errno == ERANGE && ( int_rtrn == LONG_MAX || int_rtrn == LONG_MIN ) ) cout << "OVERFLOW";

	} while ( !( int_rtrn >= rangeMin && int_rtrn <= rangeMax )
			|| (errno == ERANGE && ( int_rtrn == LONG_MAX || int_rtrn == LONG_MIN ) ) );

	return int_rtrn;
}

//////////////////////////////////////////////floating point input ///////
float swansonInput::getFloat(string prompt){
	return getFloat( prompt, FLT_MIN, FLT_MAX);
}
float swansonInput::getFloat(string prompt, float rangeMin, float rangeMax){
	return static_cast<float> ( getDouble( prompt, rangeMin, rangeMax) );
}
double swansonInput::getDouble(string prompt){
	return getDouble( prompt, DBL_MIN, DBL_MAX);

}
double swansonInput::getDouble(string prompt, double rangeMin, double rangeMax){
	double double_rtrn;
	int attempts = 0;
	string parse_string;
	bool firstTimeThrough = true;


	do {
		if(!firstTimeThrough){
			cout << "Please keep the input within these bounds ["
				 << rangeMin << " - " << rangeMax << "]";
		}
		firstTimeThrough=false;
		parse_string = swansonInput::getString(prompt);

		//TODO use errno or HUGE_VAL to check for overflow
		while( !swansonString::allNumbersFloat(parse_string) || parse_string.empty()){
			attempts++;
			if( attempts > MAX_ATTEMPTS ) return 0;

			cout << "lets try to restrain ourselves to only valid floating point numbers";
			parse_string = swansonInput::getString(prompt);
		}


		double_rtrn = strtod(parse_string.c_str(),NULL);


	} while ( !( double_rtrn >= rangeMin && double_rtrn <= rangeMax )
			|| (errno == ERANGE && ( double_rtrn == LONG_MAX || double_rtrn == LONG_MIN ) ));

	return double_rtrn;
}

/////////////////////////////////////////////////////////////////////////
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
