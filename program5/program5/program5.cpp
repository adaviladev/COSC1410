// 1410
// Program 5
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 3/2/2015
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int NUMOFGRADES = 20;

int getScore(int, int);
void getStats(double &, double &);
void printGradeRange(int, double, double);

int main(){
	double sd = 0, mean = 0;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
	getStats(sd, mean);
	printGradeRange(NUMOFGRADES, sd, mean);
	return 0;
}
int getScore(int min, int max){
	int randNum = rand() % (max - min) + (min + 1);
	return randNum;
}
void  getStats(double &sd, double &mean){
	double grade = 0;
	double gradeSquare = 0;
	srand(time(NULL));
	int tempRand, row = 0, col = 0;
	for (int i = 0; i < NUMOFGRADES; i++){
		if (i < NUMOFGRADES / 5){
			tempRand = getScore(0, 100);
		}
		else{
			tempRand = getScore(40, 70);
		}
		grade += tempRand;
		gradeSquare += tempRand * tempRand;
		if (col < 4){
			cout << setw(3) << i + 1 << ":" << setw(3) << tempRand << " | ";
			col++;
		}
		else{
			cout << setw(3) << i + 1 << ":" << setw(3) << tempRand << endl;
			col = 0;
			row++;
		}
	}
	mean = grade / NUMOFGRADES;
	sd = sqrt((gradeSquare / NUMOFGRADES) - (pow(grade / NUMOFGRADES, 2)));
}
void  printGradeRange(int numOfGrades, double std, double mean){
	cout << "\nNumber of grades: " << numOfGrades << endl;
	cout << "Mean Score: \t " << setw(6) << mean << endl;
	cout << "Std Deviation: \t " << setw(6) << std << endl << endl;
	cout << "Ranges of Letter Grade:" << endl << endl;
	cout << "A: " << setw(5) << mean + std * 1.5 << " to 100.00" << endl;
	cout << "B: " << setw(5) << mean + std * .5 << " to " << setw(5) << mean + std * 1.5 << endl;
	cout << "C: " << setw(5) << mean - std * .5 << " to " << setw(5) << mean + std * .5 << endl;
	cout << "D: " << setw(5) << mean - std * 1.5 << " to " << setw(5) << mean - std * .5 << endl;
	cout << "F: " << setw(5) << "0" << " to " << setw(5) << mean - std * 1.5 << endl;

	cin.get();
}