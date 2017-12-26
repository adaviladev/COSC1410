// 1410
// Program 8
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/1/2015
#ifndef __AUTOCLASS_H__
#define __AUTOCLASS_H__
#include <string>
using namespace std;

//Assigns the number of students in the class
const int NUM_OF_CARS = 100 , MAKE_LIMIT = 20;

class Auto{
	// fill in here
	public:
		Auto();
		char _make[MAKE_LIMIT];
		int _year;
		string _model;
		string _color;
		double _price;

		void setAll(char mk[] , string, string, int, double);
		double getPrice();
		char* getMake();
		void display(Auto);
};
#endif