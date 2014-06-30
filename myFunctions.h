#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

#include <list>

using namespace std;


class swansonString {
	public:
	static bool isALetter(char character);
	static bool isANumber(char character);
	static bool allLetters(string letterString);
	static bool allLetters(string letterString, char permitedChars[], int arraySize);
	static bool allNumbers(string numberString);
	static void seperateWords(string myString, list<string>& seperateWords);
	static string lowerCase(string caseString);
	static string upperCase(string caseString);
};

class swansonInput {
	public:
	static string getString(string prompt);
	static int getInt(string prompt);
	//static int getInt(string prompt, int rangeMax, int rangeMin);
	static bool yesNo(string prompt);

	private:
	//static bool intOverflow(string numString);
};

#endif /* MYFUNCTIONS_H_ */
