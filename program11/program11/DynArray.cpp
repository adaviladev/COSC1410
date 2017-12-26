// Adrian Davila
// Stephen Huang
// TA: Salah Taamneh
// Program 11
// 4/27/2015
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "DynArray.h"
using namespace std;

DynArray::DynArray(){
	
}
DynArray::DynArray(int newLength){
	INIT_SIZE = newLength;
}

void DynArray::showArray(){
	for (int i = 0; i < LIST_LENGTH; i++){
		// Displays the values along with their position in the pointer array
		cout << "value: " << setw(4) << i << setw(8) << **(_dynArr + i) << endl;
	}
}

void DynArray::addElem(int newVal){
	// Check if the total number of elements exceeds the current 
	// initialized size and then increments the element count.
	if (INIT_SIZE > LIST_LENGTH){
		// If no, the value is added
		*(_dynArr + LIST_LENGTH) = new int(newVal);
	} else {
		// If yes, the array size is doubled and then added.
		doubleSize();
		*(_dynArr + LIST_LENGTH) = new int(newVal);
	}
	LIST_LENGTH++;
}

void DynArray::doubleSize(){
	// Assigns the main pointer to a temporary pointer.
	int **tempArr = new (nothrow) int*[INIT_SIZE * 2];
	// Assigns the address to a new temporary address.
	for (int i = 0; i < LIST_LENGTH; i++){
		*(tempArr + i) = *(_dynArr + i);
	}
	/*
	* Deletes the original main pointer,
	* Assigns the address of the temporary pointer to the main,
	* and assigns a value of NULL to the temporary pointer.
	*/
	delete[] _dynArr;
	_dynArr = tempArr;
	tempArr = NULL;

	INIT_SIZE *= 2;
	cout << "double size: " << INIT_SIZE << endl;
}