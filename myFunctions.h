#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

#include <list>
#include <string>

using namespace std;

class swansonString {
public:
   //TODO deprecate in favor of methods in cctype
   static bool IsALetter ( char character );
   static bool IsANumber ( char character );
   static bool AllNumbers ( string numberString );
   static bool AllNumbersFloat ( string numberString );
   static bool AllLetters ( string letterString );
   static bool AllLetters ( string letterString , char permitedChars[] ,
         int arraySize );
   //TODO deprecate and use stringstream
   static void SeperateWords ( string myString , list<string>& seperateWords );
   static string LowerCase ( string caseString );
   static string UpperCase ( string caseString );
};

class swansonInput {
public:
   static string GetString ( string prompt );
   static string GetOneWord ( string prompt );

   static int GetInt ( string prompt );
   static int GetInt ( string prompt , int rangeMax , int rangeMin );
   static long int GetLong ( string prompt );
   static long int GetLong ( string prompt , long int rangeMin ,
         long int rangeMax );

   static float GetFloat ( string prompt );
   static float GetFloat ( string prompt , float rangeMin , float rangeMax );
   static double GetDouble ( string prompt );
   static double GetDouble ( string prompt , double rangeMin ,
         double rangeMax );

   static bool yesNo ( string prompt );
};

class swansonUtil {
public:
   static bool Contains ( long int var , long int values[] , int range );
   static bool Contains ( int var , int values[] , int range );
   static bool Contains ( float var , float values[] , int range );
   static bool Contains ( double var , double values[] , int range );
   static bool Contains ( bool var , bool values[] , int range );
   static bool Contains ( string var , string values[] , int range );
   static bool Contains ( char var , char values[] , int range );
   //TODO add overload bool for seeded random
   static int RandomInRange ( int min , int max );
   static void InsertElement ( int val , int sortArray[] , int numHolding );
   static void GetMappedRandomInts ( int valuesOut[] , int range ,
         const int numGenerateValues );
};

#endif /* MYFUNCTIONS_H_ */
