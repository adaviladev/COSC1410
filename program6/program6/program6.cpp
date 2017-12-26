// 1410
// Program 6
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 3/11/2015
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int NUMOFGRADES = 100;

int getScore(int, int);
void getScores(int *);
double getMean(int *);
double getStd(int *, double);
void computeRange( double * , int , double , double );
void computeGrade(int *, double *, char * , int *);
void printGradeRange(double * , int * , double , double );

void main(){
	int score[NUMOFGRADES], counter[5] = { 0 }, col = 0, row = 0;
	char grade[NUMOFGRADES];
	double range[4];
	double std = 0, mean = 0;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
	getScores(score);
	mean = getMean(score);
	std = getStd(score, mean);
	computeRange( range , 4 , mean , std);
	computeGrade(score , range , grade , counter);
	for (int i = 0; i < NUMOFGRADES; i++){
		cout << "Score ";
		if (col < 2){
			cout << setw(3) << i + 1 << ":" << setw(4) << score[i] << setw(3) << grade[i] << "|\t";
			col++;
		} else{
			cout << setw(3) << i + 1 << ":" << setw(4) << score[i] << setw(3) << grade[i] << endl;
			col = 0;
		}
	}
	printGradeRange(range , counter , mean , std );
}
int getScore(int min, int max){
	int randNum = rand() % (max - min) + (min + 1);
	return randNum;
}
void getScores(int * scoreArr){
	srand(time(NULL));
	int tempRand, row = 0, col = 0;
	for (int i = 0; i < NUMOFGRADES; i++){
		if (i < NUMOFGRADES / 5){
			scoreArr[i] = getScore(0, 100);
		} else{
			scoreArr[i] = getScore(40, 70);
		}
	}
}
double getMean(int * scoreArr){
	double sum = 0;
	for (int i = 0; i < NUMOFGRADES; i++){
		sum += scoreArr[i];
	}
	return (sum / NUMOFGRADES);
}
double getStd(int * scoreArr, double mean){
	double gradeSquare = 0;
	double std = 0;
	for (int i = 0; i < NUMOFGRADES; i++){
		std += pow((scoreArr[i] - mean), 2);
	}
	std /= NUMOFGRADES;
	std = sqrt(std);
	return std;
}
void computeRange(double * range, int rangeSize, double mean, double std){
	range[0] = mean + (1.5 * std);
	range[1] = mean + (.5 * std);
	range[2] = mean - (.5 * std);
	range[3] = mean - (1.5 * std);
}
void computeGrade(int * scoreArr , double * range ,  char * gradeArr , int * ctr ){
	for (int i = 0; i < NUMOFGRADES; i++){
		if (scoreArr[i] > range[0]){
			gradeArr[i] = 'A';
			ctr[0]++;
		} else if (scoreArr[i] > range[1]){
			gradeArr[i] = 'B';
			ctr[1]++;
		} else if (scoreArr[i] > range[2]){
			gradeArr[i] = 'C';
			ctr[2]++;
		} else if (scoreArr[i] > range[3]){
			gradeArr[i] = 'D';
			ctr[3]++;
		} else {
			gradeArr[i] = 'F';
			ctr[4]++;
		}
	}
}
void  printGradeRange(double * range , int * ctr , double mean, double std){
	cout << "\n\nNumber of grades: " << NUMOFGRADES << endl;
	cout << "Mean Score: \t " << setw(6) << mean << endl;
	cout << "Std Deviation: \t " << setw(6) << std << endl << endl;
	cout << "Ranges of Letter Grade:" << endl << endl;
	cout << "A: " << setw(5) << range[0] << " to 100.00" << setw(4) << ctr[0] << endl;
	cout << "B: " << setw(5) << range[1] << " to " << setw(6) << range[0] << setw(4) << ctr[1] << endl;
	cout << "C: " << setw(5) << range[2] << " to " << setw(6) << range[1] << setw(4) << ctr[2] << endl;
	cout << "D: " << setw(5) << range[3] << " to " << setw(6) << range[2] << setw(4) << ctr[3] << endl;
	cout << "F: " << setw(5) << "0" << " to " << setw(6) << range[3] << setw(4) << ctr[4] << endl;
	cin.get();
}