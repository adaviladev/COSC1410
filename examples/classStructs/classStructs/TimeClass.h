#ifndef __TIMECLASS_H__
#define __TIMECLASS_H__

struct Time
{
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
};

class TimeClass
{
public:
	TimeClass();
	TimeClass(int hours, int minutes, int seconds);
	TimeClass(Time time);

	/*
	Rules:
	1) Hours must be greater than or equal to 0
	2) Hours must be rule 2.....
	*/
	bool setHours(int hours);
	bool setMinutes(int minutes);
	bool setSeconds(int seconds);
	bool set(int hours, int minutes, int seconds);
	bool set(Time time);
	void print();

	int getHours();
	int getMinutes();
	int getSeconds();
	Time getTime();
private:
	Time _time;
	bool isNumberPositive(int number);
};

#endif