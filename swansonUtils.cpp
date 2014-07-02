#include "myFunctions.h"
#include <cstdlib>

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

int swansonUtil::RandomInRange ( int min , int max ) {
   int random;
   int range = max - min + 1;
   if ( range == 0 )
      return min;
   random = (rand() % range) + min;
   return random;
}

/*
 void insertElement ( int val, int sortArray[], int numHolding){
 int i=0;
 for ( ; i < numHolding ; i++ ){
 if ( val < sortArray[i] ){
 for ( int j = numHolding ; j > i ; j-- ){
 sortArray[ j ] = sortArray [ j - 1 ];
 }
 break;
 }
 }
 sortArray [ i ] = val;
 }*/
