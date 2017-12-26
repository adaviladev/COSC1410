// 1410
// Program 8
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/1/2015
#ifndef __DEALERCLASS_H__
#define __DEALERCLASS_H__
#include "Auto.h"
using namespace std;

class Dealer{
	public:
		Auto _cars[NUM_OF_CARS];
		int _numOfcars;
		//int _recNum = 0;
		Dealer();

		void addCar(int& recNum, char  make[], string& model, string& color, int& year, double& price);
		int getNumOfCars();
		void displayAll();
		void displayWithinPriceRange(double, double);
		void displayByMake(char make[]);
};
#endif