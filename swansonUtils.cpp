#include "myFunctions.h"

bool swansonUtil::contains(long int var, long int values[], int range){
	for ( int i = 0 ; i < range ; i++ ){
		if ( values[i] == var ) return true;
	}
	return false;
}
bool swansonUtil::contains(int var, int values[], int range){
	for ( int i = 0 ; i < range ; i++ ){
		if ( values[i] == var ) return true;
	}
	return false;
}
bool swansonUtil::contains(double var, double values[], int range){
	for ( int i = 0 ; i < range ; i++ ){
			if ( values[i] == var ) return true;
		}
		return false;
}
bool swansonUtil::contains(float var, float values[], int range){
	for ( int i = 0 ; i < range ; i++ ){
			if ( values[i] == var ) return true;
		}
		return false;
}

bool swansonUtil::contains(bool var, bool values[], int range){
	for ( int i = 0 ; i < range ; i++ ){
			if ( values[i] == var ) return true;
		}
		return false;
}
bool swansonUtil::contains(string var, string values[], int range){
	for ( int i = 0 ; i < range ; i++ ){
			if ( values[i] == var ) return true;
		}
		return false;
}
bool swansonUtil::contains(char var, char values[], int range){
	for ( int i = 0 ; i < range ; i++ ){
			if ( values[i] == var ) return true;
		}
		return false;
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
