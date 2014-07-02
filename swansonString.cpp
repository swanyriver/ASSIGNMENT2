#include <string>
#include <list>
#include "myFunctions.h"

using namespace std;

bool swansonString::isALetter ( char character ) {
   if ( (character >= 'a' && character <= 'z')
         || (character >= 'A' && character <= 'Z') )
      return true;
   else
      return false;
}

bool swansonString::isANumber ( char character ) {
   if ( character >= '0' && character <= '9' )
      return true;
   else
      return false;
}

bool swansonString::allNumbers ( string numberString ) {
   int i = 0;
   if ( numberString.length() > 1 && numberString.at(0) == '-' ) {
      i++;
   }
   for ( ; i < numberString.length() ; i++ ) {
      if ( !isANumber(numberString.at(i)) )
         return false;
   }
   return true;
}

bool swansonString::allNumbersFloat ( string numberString ) {
   string tempString;
   int numDots = 0;
   int dotLocation;

   for ( int i = 0 ; i < numberString.length() ; i++ ) {
      if ( numberString.at(i) == '.' ) {
         numDots++;
         dotLocation = i;
      }
   }
   if ( numDots > 1 )
      return false;
   else if ( numDots == 0 )
      return allNumbers(numberString);
   else if ( numDots == 1 ) {
      for ( int i = 0 ; i < numberString.length() ; i++ ) {
         if ( i != dotLocation )
            tempString += numberString.at(i);
      }
      return allNumbers(tempString);
   }

   return false;
}

bool swansonString::allLetters ( string letterString ) {
   for ( int i = 0 ; i < letterString.length() ; i++ ) {
      if ( !isALetter(letterString.at(i)) )
         return false;
   }
   return true;
}
bool swansonString::allLetters ( string letterString , char permitedChars[] ,
      int arraySize ) {

   bool isAPermitedChar;

   for ( int i = 0 ; i < letterString.length() ; i++ ) {
      isAPermitedChar = false;

      for ( int j = 0 ; j < arraySize ; j++ ) {
         if ( letterString.at(i) == permitedChars[j] ) {
            isAPermitedChar = true;
         }
      }

      if ( !(isALetter(letterString.at(i)) || isAPermitedChar) ) {
         return false;
      }
   }
   return true;
}

void swansonString::seperateWords ( string myString ,
      list<string>& seperateWords ) {
   string currentWord;

   seperateWords.clear();

   int i = 0;
   while ( i < myString.length() && !swansonString::isALetter(myString.at(i)) )
      i++; //find first letter;

   while ( i < myString.length() ) {
      if ( swansonString::isALetter(myString.at(i)) ) {
         currentWord += myString.at(i);
         i++;
      } else {
         if ( !currentWord.empty() )
            seperateWords.push_back(currentWord);
         currentWord.clear();
         while ( i < myString.length()
               && !swansonString::isALetter(myString.at(i)) )
            i++; //find next letter;
      }
   }
   if ( !currentWord.empty() )
      seperateWords.push_back(currentWord);

}

string swansonString::lowerCase ( string caseString ) {
   string lowerCaseString = "";
   for ( int i = 0 ; i < caseString.length() ; i++ ) {
      if ( swansonString::isALetter(caseString.at(i)) ) {
         if ( caseString.at(i) >= 'A' && caseString.at(i) <= 'Z' ) {
            lowerCaseString += (caseString.at(i) + ('a' - 'A'));
         } else
            lowerCaseString += caseString.at(i);
      }
   }
   return lowerCaseString;
}

string swansonString::upperCase ( string caseString ) {
   string upperCaseString = "";
   for ( int i = 0 ; i < caseString.length() ; i++ ) {
      if ( swansonString::isALetter(caseString.at(i)) ) {
         if ( caseString.at(i) >= 'a' && caseString.at(i) <= 'z' ) {
            upperCaseString += (caseString.at(i) + ('A' - 'a'));
         } else
            upperCaseString += caseString.at(i);
      }
   }
   return upperCaseString;
}
