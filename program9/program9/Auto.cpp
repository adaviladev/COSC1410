// 1410
// Program 9
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/13/2015
#include "Auto.h"
#include <iostream>
#include <iomanip>
using namespace std;

Auto::Auto(){
	// Unnecessary
}
char* Auto::getMake(){
		return _make;
}
double Auto::getPrice(){
	if (_price >= 0){
		return _price;
	}
	return 0;
}
void Auto::setAll(char mk[] , string model, string color , int year, double price) {
	//Ensures that make is entered with in initial caps format
	//Sets all variables for current _cars object
	/* Start _make string formatting */
	// Sets the first character to upper case and all remaining characters to lower case
	int ind = 0;
	_make[0] = toupper(mk[0]);
	while (_make[ind] != '\0'){
		_make[ind] = tolower(mk[ind]);
		ind++;
	}
	/* End _make string formatting */
	_model				= model;
	_year				= year;
	_color				= color;
	_price				= price;/**/
}
void Auto::display(Auto _carArr){
	//Displays provided car object
	cout << setiosflags(ios::left) << setw(10) << _carArr._make 
		<< setiosflags(ios::left) << setw(10) << _carArr._model
		<< setiosflags(ios::left) << setw(6) << _carArr._year
		<< setiosflags(ios::left) << setw(7) << _carArr._color
		<< "$" << setw(7) << resetiosflags(ios::left) << _carArr._price << endl;
}