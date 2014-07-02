#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

#include <list>
#include <string>

using namespace std;

class swansonString {
public:
   static bool isALetter ( char character );
   static bool isANumber ( char character );
   static bool allNumbers ( string numberString );
   static bool allNumbersFloat ( string numberString );
   static bool allLetters ( string letterString );
   static bool allLetters ( string letterString , char permitedChars[] ,
         int arraySize );
   static void seperateWords ( string myString , list<string>& seperateWords );
   static string lowerCase ( string caseString );
   static string upperCase ( string caseString );
};

class swansonInput {
public:
   static string getString ( string prompt );
   static string getOneWord ( string prompt );

   static int getInt ( string prompt );
   static int getInt ( string prompt , int rangeMax , int rangeMin );
   static long int getLong ( string prompt );
   static long int getLong ( string prompt , long int rangeMin ,
         long int rangeMax );

   static float getFloat ( string prompt );
   static float getFloat ( string prompt , float rangeMin , float rangeMax );
   static double getDouble ( string prompt );
   static double getDouble ( string prompt , double rangeMin ,
         double rangeMax );

   static bool yesNo ( string prompt );
};

class swansonUtil {
public:
   static bool contains ( long int var , long int values[] , int range );
   static bool contains ( int var , int values[] , int range );
   static bool contains ( float var , float values[] , int range );
   static bool contains ( double var , double values[] , int range );
   static bool contains ( bool var , bool values[] , int range );
   static bool contains ( string var , string values[] , int range );
   static bool contains ( char var , char values[] , int range );
   static int randomInRange ( int min , int max );
};

#endif /* MYFUNCTIONS_H_ */
