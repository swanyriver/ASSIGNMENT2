/***********************************************************
 * Author: Brandon Swanson
 * Date Created: 06-29-2014
 * Last Modification Date: 07-01-2014
 * Filename: swansonUtils.cpp
 *
 * Overview:
 *
 * Input:
 *
 * Output:
 *
 ***********************************************************/

#include "myFunctions.h"
#include <cstdlib>
#include <ctime>

bool swansonUtil::Contains ( long int var , long int values[] , int range ) {
   for ( int i = 0 ; i < range ; i++ ) {
      if ( values[i] == var )
         return true;
   }
   return false;
}
bool swansonUtil::Contains ( int var , int values[] , int range ) {
   for ( int i = 0 ; i < range ; i++ ) {
      if ( values[i] == var )
         return true;
   }
   return false;
}
bool swansonUtil::Contains ( double var , double values[] , int range ) {
   for ( int i = 0 ; i < range ; i++ ) {
      if ( values[i] == var )
         return true;
   }
   return false;
}
bool swansonUtil::Contains ( float var , float values[] , int range ) {
   for ( int i = 0 ; i < range ; i++ ) {
      if ( values[i] == var )
         return true;
   }
   return false;
}

bool swansonUtil::Contains ( bool var , bool values[] , int range ) {
   for ( int i = 0 ; i < range ; i++ ) {
      if ( values[i] == var )
         return true;
   }
   return false;
}

bool swansonUtil::Contains ( string var , string values[] , int range ) {
   for ( int i = 0 ; i < range ; i++ ) {
      if ( values[i] == var )
         return true;
   }
   return false;
}

bool swansonUtil::Contains ( char var , char values[] , int range ) {
   for ( int i = 0 ; i < range ; i++ ) {
      if ( values[i] == var )
         return true;
   }
   return false;
}

void swansonUtil::SeedRandom () {
   srand ( time ( 0 ) );
}

int swansonUtil::GetRandomInRange ( int max ) {
   return GetRandomInRange ( 0 , max );
}

int swansonUtil::GetRandomInRange ( int min , int max ) {

   int random;
   int range = max - min + 1;
   if ( range == 0 )
      return min;
   random = (rand () % range) + min;
   return random;
}

void swansonUtil::InsertElement ( int val , int sortArray[] , int numHolding ) {
   int i = 0;
   for ( ; i < numHolding ; i++ ) {
      if ( val < sortArray[i] ) {
         for ( int j = numHolding ; j > i ; j-- ) {
            sortArray[j] = sortArray[j - 1];
         }
         break;
      }
   }
   sortArray[i] = val;
}

void swansonUtil::GetMappedRandomInts ( int valuesOut[] , int rangeBegining ,
      int rangeEnd , const int numGenerateValues ) {
   int nextSelection;
   list<int> selectionsList;
   valuesOut[0] = swansonUtil::GetRandomInRange ( rangeBegining , rangeEnd );
   rangeEnd--;
   for ( int i = 1 ; i < numGenerateValues ; ++i ) {
      nextSelection = swansonUtil::GetRandomInRange ( rangeBegining ,
            rangeEnd );
      rangeEnd--;
      selectionsList.clear ();
      for ( int j = 0 ; j < i ; j++ ) {
         selectionsList.push_back ( valuesOut[j] );
      }
      do {
         int increment = 0;
         while ( !selectionsList.empty ()
               && selectionsList.front () <= nextSelection ) {
            increment++;
            selectionsList.pop_front ();
         }
         nextSelection += increment;
      } while ( !selectionsList.empty ()
            && selectionsList.front () <= nextSelection );
      swansonUtil::InsertElement ( nextSelection , valuesOut , i );
   }

}

