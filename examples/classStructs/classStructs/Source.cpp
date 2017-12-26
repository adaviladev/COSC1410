#include<iostream>
#include "TimeClass.h"

using namespace std;

int main()
{
	Time time3;
	time3.hours = 1;
	time3.minutes = 33;
	time3.seconds = 29;
	TimeClass timeClass3(time3);

	TimeClass timeClass1;
	TimeClass timeClass2(2, 30, 20);
	timeClass1.setHours(3);
	timeClass1.setHours(-1);

	cout << "timeClass1: Default Constructor" << endl;
	timeClass1.print();

	cout << "timeClass2: Constructor with 3 parameters" << endl;
	timeClass2.print();

	cout << "timeClass3: Constructor with struct as parameter" << endl;
	timeClass3.print();

	timeClass1.set(5, 45, 20);
	cout << "timeClass1: After calling set function" << endl;
	timeClass1.print();
	system("pause");
	return 0;
}