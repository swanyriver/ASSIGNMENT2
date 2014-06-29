#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

#include <list>

using namespace std;


class swansonString {
	public:
	static bool isALetter(char character);
	static bool allLetters(string letterString);
	static bool allLetters(string letterString, char permitedChars[], int arraySize);
	static void seperateWords(string myString, list<string>& seperateWords);
};

class swansonInput {
	public:
	static string getString(string prompt);
};

#endif /* MYFUNCTIONS_H_ */
