// Adrian Davila
// Stephen Huang
// TA: Salah Taamneh
// Program 11
// 4/27/2015

/*
* FULL DISCLOSURE
* I'm not entirely sure that this program does EXACTLY what part II asks for;
* mainly because I wasn't sure how to debug it, but the address and values that 
* were printed were unique.
*/

#include <iostream>
#include <limits>
#include <cstdlib>
#include "DynArray.h"

using namespace std;
const char YES = 'Y';
const char NO = 'N';

int main(){
	DynArray arr1;
	int inputValue;
	char option = 'Y';
	/*
	* No direction was given on input, so I provided a simple menu
	* It checks if you want to continue after every value entered.
	* The commented section below can be uncommented to provided faster
	* data entry
	*/
	do{
		cout << "Enter an integer: ";
		cin >> inputValue;
		// Makes
		while (cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "*** ERROR: The value you have entered is an INVALID entry." << endl << "Please enter an integer: ";
			cin >> inputValue;
		}
		arr1.addElem(inputValue);
		cout << "Would you like to enter another value? (Y/N): ";
		cin >> option;
		while (cin.fail() || (toupper(option) != NO && toupper(option) != YES)){//
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "*** ERROR: The value you have entered is an INVALID entry." << endl << "Please Enter Y or N: ";
			cin >> option;
		}
	} while (toupper(option) == YES);
	
	arr1.showArray();

	/*
	
	* I wasn't exactly sure how to test for heap memory shortage, 
	* so I kept increasing the input limit (val) and it seemed to 
	* check if it crashed or returned an error and nothing happened.
	* Uncomment this section to provide faster data input.

	DynArray a;
	cout << endl;
	a.showArray();
	cout << endl;
	int val = 10000000;
	for (int i = 0; i<val; i++) {
		a.addElem(100 + i);
		if (i == val - 1){
			cout << endl;
			//a.showArray();
			cout << endl;
		}
	}*/
	system("pause");
	return 0;
}
