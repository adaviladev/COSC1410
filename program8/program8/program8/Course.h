// 1410
// Program 8
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/1/2015
#ifndef __COURSECLASS_H__
#define __COURSECLASS_H__

//Assigns the number of students in the class
const int NUM_OF_STUDENTS = 100;

struct Student{
	int id;
	int score;
};

class Course{
	public:
		Course();
		void print();
	private:
		int setID();
		int setScore(int, int);

		void selectionSort();
		bool checkIfValueExists(int);
		Student _student[NUM_OF_STUDENTS];
		Student _idSort[NUM_OF_STUDENTS];
		Student _scoreSort[NUM_OF_STUDENTS];
};
#endif