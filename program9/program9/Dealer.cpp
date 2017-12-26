// 1410
// Program 9
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/13/2015
#include "Dealer.h"
#include "Auto.h"
#include <iostream>
using namespace std;

Dealer::Dealer(){
	_numOfcars = 0;
	for (int i = 0; i < NUM_OF_CARS; i++){
		_cars[i]._make[0] = toupper(_cars[i]._make[0]);
		_cars[i]._model[0] = toupper(_cars[i]._model[0]);
		int ind = 1;
	}
}
void Dealer::addCar(int& recNum, char  make[], string& model, string& color, int& year, double& price){
	make[0] = toupper(make[0]);
	int ind = 1;
	while (make[ind] != '\0'){
		make[ind] = tolower(make[ind]);
		ind++;
	}
	// After formatting _make, sets the values for this _car instance
	_cars[_numOfcars].setAll(make, model, color, year, price);
}
int Dealer::getNumOfCars(){
	return _numOfcars;
}
void Dealer::displayAll() {
	for (int i = 0; i < _numOfcars; i++){
		_cars[i].display(_cars[i]);
	}
}
void Dealer::displayWithinPriceRange(double min , double max){
	for (int i = 0; i < _numOfcars; i++){
		// Get price of current _car object for comparison
		double price = _cars[i].getPrice();
		if (price >= min && price <= max){
			// If within provided range, displays _car object
			_cars[i].display(_cars[i]);
		}
	}
}

void Dealer::displayByMake(char desiredMake[]){
	desiredMake[0] = toupper(desiredMake[0]);
	int ind = 1;
	while (desiredMake[ind] != '\0'){
		desiredMake[ind] = tolower(desiredMake[ind]);
		ind++;
	}
	for (int i = 0; i < _numOfcars; i++){
		//compares _make with user input. If match, display _car object
		if (strcmp(_cars[i].getMake(), desiredMake) == 0){
			_cars[i].display(_cars[i]);
		}
	}
}