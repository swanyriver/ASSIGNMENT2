#include <iostream>
#include "myFunctions.h"

void newMappedRandomInts ( int valuesOut[] , int rangeBegin , int rangeEnd, int numValuesIn = 0, int numValuesOut = 1 ) {
   int nextSelection;
   list<int> selectionsList;

   numValuesOut+=numValuesIn;
   rangeEnd-=numValuesIn;

   if(numValuesIn == 0 && numValuesOut > 0){
      valuesOut[0] = swansonUtil::GetRandomInRange(rangeBegin, rangeEnd);
      numValuesIn++;
      rangeEnd--;
   }

   for (  ; numValuesIn < numValuesOut ; ++numValuesIn ) {
      nextSelection = swansonUtil::GetRandomInRange(rangeBegin, rangeEnd);
      cout << "in:" << nextSelection;
      rangeEnd--;
      selectionsList.clear();
      for ( int j = 0 ; j < numValuesIn ; j++ ) {
         selectionsList.push_back(valuesOut[j]);
      }
      do {
         int increment = 0;
         while ( !selectionsList.empty()
               && selectionsList.front() <= nextSelection ) {
            increment++;
            selectionsList.pop_front();
         }
         nextSelection += increment;
      } while ( !selectionsList.empty()
            && selectionsList.front() <= nextSelection );
      swansonUtil::InsertElement(nextSelection, valuesOut, numValuesIn);
      cout << "  out:" << nextSelection << endl;
   }

}

int main(){
   cout << "random number 0 to 60 " << swansonUtil::GetRandomInRange(60) << endl;
   cout << "random number 10 to 20 " << swansonUtil::GetRandomInRange(10,20);

   int randoms[7];

   newMappedRandomInts(randoms,0,10,0,7);

   cout << endl << "7 random numbers 0 to 10: ";
   for (int var = 0; var < 7; ++var) {
      cout << randoms[var] << ",";
   }

   int randoms2[20];

   randoms2[0]=11;
   randoms2[1]=14;
   randoms2[2]=16;
   randoms2[3]=17;
   randoms2[4]=19;

   newMappedRandomInts(randoms2,10,30,5,3);

   cout << endl << "7 random numbers 0 to 10: ";
   for (int var = 0; var < 8; ++var) {
       cout << randoms2[var] << ",";
   }
   cout << "/";
   for (int var = 8; var < 20; ++var) {
          newMappedRandomInts(randoms2,10,30,var,1);
          cout << randoms2[var] << ",";
   }
   cout << endl;
   for (int var = 8; var < 20; ++var) {
      cout << randoms2[var] << ",";
   }

}




