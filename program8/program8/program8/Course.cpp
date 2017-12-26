// 1410
// Program 8
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/1/2015
#include "Course.h"
#include <iostream>
#include <iomanip>

using namespace std;
const int idMin = 0, idMax = 10;
const int SORT_OPTION = 0;


Course::Course(){
	
	// Builds the three arrays
	int tempScore, row = 0, col = 0;
	for (int i = 0; i < NUM_OF_STUDENTS; i++){
		//Generates grades with 20% between 0 and 100 and the rest between 40 and 70
		if (i < NUM_OF_STUDENTS / 5){
			tempScore = setScore(0, 100);
		}
		else{
			tempScore = setScore(40, 70);
		}
		//Set all arrays identically for sorting later
		_idSort[i].id = _scoreSort[i].id = _student[i].id = setID();
		//Reiterates through the array as it's being built and checks to see if the ID has been assigned yet
		while (checkIfValueExists(i)){
			_idSort[i].id = _scoreSort[i].id = _student[i].id = setID();
		}
		_idSort[i].score = _scoreSort[i].score = _student[i].score = tempScore;
	}
}
bool Course::checkIfValueExists(int ind){
	//loops through the array up until the current index (ind)
	//returns true if the ID has been assigned and generates a new number to be checked again
	for (int j = 0; j < ind; j++){
		if (_student[ind].id == _student[j].id){
			//cout << "repeat at (j , i): [" << j << ", " << ind << "]: " << _student[j].id << endl;
			return true;
		}
	}
	return false;
}
int Course::setScore(int min , int max){
	//generates randon score between provided values
	int randNum = rand() % (max - min) + (min + 1);
	return randNum;
}
int Course::setID(){
	//generates random number between idMin and idMax/NUM_OF_STUDENTS
	int randNum;
	if (NUM_OF_STUDENTS < idMax){
		randNum = rand() % (idMax - idMin) + (idMin + 1);
	} else{
		randNum = rand() % (NUM_OF_STUDENTS - idMin) + (idMin + 1);
	}
	return randNum;
}
void Course::selectionSort() {
	int i, k, indexOfNextSmallest , indexOfNextLargest;
	//declare temporary Student variable
	Student temp;
	
	//Begin sort by ID
	for (i = 0; i < NUM_OF_STUDENTS - 1; i++){
		indexOfNextSmallest = i;
		for (k = i + 1; k < NUM_OF_STUDENTS; k++){
			if (_idSort[k].id < _idSort[indexOfNextSmallest].id){
				indexOfNextSmallest = k;
			}
		}
		temp = _idSort[i];
		_idSort[i] = _idSort[indexOfNextSmallest];
		_idSort[indexOfNextSmallest] = temp;
	}
	//End sort by ID

	//Begin sort by Score
	for (i = 0; i < NUM_OF_STUDENTS -1 ; i++){
		indexOfNextLargest = i;
		for (k = i + 1; k < NUM_OF_STUDENTS; k++){
			if (_scoreSort[k].score > _scoreSort[indexOfNextLargest].score){
				indexOfNextLargest = k;
			}
		}
		temp = _scoreSort[i];
		_scoreSort[i] = _scoreSort[indexOfNextLargest];
		_scoreSort[indexOfNextLargest] = temp;
	}/**/
	//End sort by Score
}
void Course::print(){
	selectionSort();
	//Prints out all three arrays by index
	cout << "  Before Sort:\t     After Sort by ID:\t\tAfter Sort by Score:" << endl;
	cout << "     ID  Score\t\t  ID  Score\t\t  ID  Score" << endl << endl;
	for (int i = 0; i < NUM_OF_STUDENTS; i++){
		cout << setw(3) << (i+1) << " " << setw(4) << _student[i].id
			<< " " << setw(6) << _student[i].score << "\t";
		cout << "\t" << setw(4) << _idSort[i].id
			<< " " << setw(6) << _idSort[i].score << "\t";
		cout << " \t" << setw(4) << _scoreSort[i].id
			<< " " << setw(6) << _scoreSort[i].score << "\t" << endl;
	}/**/
	cout << endl;
}