/***********************************************************
 * Author: Brandon Swanson
 * Date Created: 06-29-2014
 * Last Modification Date: 07-01-2014
 * Filename: swansonString.cpp
 *
 * Overview:
 *
 * Input:
 *
 * Output:
 *
 ***********************************************************/

#include <string>
#include <list>
#include "myFunctions.h"

using namespace std;

bool swansonString::IsALetter ( char character ) {
   if ( (character >= 'a' && character <= 'z')
         || (character >= 'A' && character <= 'Z') )
      return true;
   else
      return false;
}

bool swansonString::IsANumber ( char character ) {
   if ( character >= '0' && character <= '9' )
      return true;
   else
      return false;
}

bool swansonString::AllNumbers ( string numberString ) {
   int i = 0;
   if ( numberString.length () > 1 && numberString.at ( 0 ) == '-' ) {
      i++;
   }
   for ( ; i < numberString.length () ; i++ ) {
      if ( !IsANumber ( numberString.at ( i ) ) )
         return false;
   }
   return true;
}

bool swansonString::AllNumbersFloat ( string numberString ) {
   string tempString;
   int numDots = 0;
   int dotLocation;

   for ( int i = 0 ; i < numberString.length () ; i++ ) {
      if ( numberString.at ( i ) == '.' ) {
         numDots++;
         dotLocation = i;
      }
   }
   if ( numDots > 1 )
      return false;
   else if ( numDots == 0 )
      return AllNumbers ( numberString );
   else if ( numDots == 1 ) {
      for ( int i = 0 ; i < numberString.length () ; i++ ) {
         if ( i != dotLocation )
            tempString += numberString.at ( i );
      }
      return AllNumbers ( tempString );
   }

   return false;
}

bool swansonString::AllLetters ( string letterString ) {
   for ( int i = 0 ; i < letterString.length () ; i++ ) {
      if ( !IsALetter ( letterString.at ( i ) ) )
         return false;
   }
   return true;
}
bool swansonString::AllLetters ( string letterString , char permitedChars[] ,
      int arraySize ) {

   bool isAPermitedChar;

   for ( int i = 0 ; i < letterString.length () ; i++ ) {
      isAPermitedChar = false;

      for ( int j = 0 ; j < arraySize ; j++ ) {
         if ( letterString.at ( i ) == permitedChars[j] ) {
            isAPermitedChar = true;
         }
      }

      if ( !(IsALetter ( letterString.at ( i ) ) || isAPermitedChar) ) {
         return false;
      }
   }
   return true;
}

void swansonString::SeperateWords ( string myString ,
      list<string>& seperateWords ) {
   string currentWord;

   seperateWords.clear ();

   int i = 0;
   while ( i < myString.length ()
         && !swansonString::IsALetter ( myString.at ( i ) ) )
      i++; //find first letter;

   while ( i < myString.length () ) {
      if ( swansonString::IsALetter ( myString.at ( i ) ) ) {
         currentWord += myString.at ( i );
         i++;
      } else {
         if ( !currentWord.empty () )
            seperateWords.push_back ( currentWord );
         currentWord.clear ();
         while ( i < myString.length ()
               && !swansonString::IsALetter ( myString.at ( i ) ) )
            i++; //find next letter;
      }
   }
   if ( !currentWord.empty () )
      seperateWords.push_back ( currentWord );

}

string swansonString::LowerCase ( string caseString ) {
   string lowerCaseString = "";
   for ( int i = 0 ; i < caseString.length () ; i++ ) {
      if ( swansonString::IsALetter ( caseString.at ( i ) ) ) {
         if ( caseString.at ( i ) >= 'A' && caseString.at ( i ) <= 'Z' ) {
            lowerCaseString += (caseString.at ( i ) + ('a' - 'A'));
         } else
            lowerCaseString += caseString.at ( i );
      }
   }
   return lowerCaseString;
}

string swansonString::UpperCase ( string caseString ) {
   string upperCaseString = "";
   for ( int i = 0 ; i < caseString.length () ; i++ ) {
      if ( swansonString::IsALetter ( caseString.at ( i ) ) ) {
         if ( caseString.at ( i ) >= 'a' && caseString.at ( i ) <= 'z' ) {
            upperCaseString += (caseString.at ( i ) + ('A' - 'a'));
         } else
            upperCaseString += caseString.at ( i );
      }
   }
   return upperCaseString;
}
