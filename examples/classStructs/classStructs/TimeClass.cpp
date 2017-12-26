#include "TimeClass.h"
#include <iostream>

using namespace std;

TimeClass::TimeClass(){
	_time.hours = 0;
	_time.minutes = 0;
	_time.seconds = 0;
}

TimeClass::TimeClass(int hours, int minutes, int seconds){
	set(hours, minutes, seconds);
}

TimeClass::TimeClass(Time time){
	set(time);
}

bool TimeClass::set(Time time){
	return set(time.hours, time.minutes, time.seconds);
}

bool TimeClass::set(int hours, int minutes, int seconds){
	return setHours(hours) && setMinutes(minutes) && setSeconds(seconds);
}

bool TimeClass::setHours(int hours){
	if (isNumberPositive(hours)){
		_time.hours = hours;
		return true;
	}

	cout << "ERROR: Hours must be POSITIVE!\n";
	return false;
}

bool TimeClass::setMinutes(int minutes){
	if (isNumberPositive(minutes)){
		_time.minutes = minutes;
		return true;
	}

	cout << "ERROR: Minutes must be POSITIVE!\n";
	return false;
}

bool TimeClass::setSeconds(int seconds){
	if (isNumberPositive(seconds)){
		_time.seconds = seconds;
		return true;
	}

	cout << "ERROR: Seconds must be POSITIVE!\n";
	return false;
}

bool TimeClass::isNumberPositive(int number){
	return number >= 0;
}

int TimeClass::getHours(){
	return _time.hours;
}

int TimeClass::getMinutes(){
	return _time.minutes;
}

int TimeClass::getSeconds(){
	return _time.seconds;
}

Time TimeClass::getTime(){
	return _time;
}

void TimeClass::print()
{
	cout << _time.hours << ":" << getMinutes() << ":" << _time.seconds << endl << endl;
}