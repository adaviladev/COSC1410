// 1410
// Program 9
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/13/2015
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Bank.h"
#include "AccountList.h"
using namespace std;

Bank::Bank(){
	bool notEOF = true;
	int i = 0;
	while (notEOF){
		notEOF = getRecord(_recNum);
		i++;
	}/**/
	selectionSort();
}
void Bank::addAccount(int id, string lastName, string firstName, double balance){
	_accounts[_recNum].setAll(id, lastName, firstName, balance);
}
int Bank::getNumOfAccounts(){
	return _recNum;
}
void Bank::displayAll() {
	for (int i = 0; i < _recNum; i++){
		AccountList _accObj = _accounts[i];
		cout << setiosflags(ios::left) << setw(10) << _accObj.getID()
			<< setiosflags(ios::left) << setw(10) << _accObj.getLastName()
			<< setiosflags(ios::left) << setw(6) << _accObj.getFirstName()
			<< "$" << setw(7) << resetiosflags(ios::left) << _accObj.getBalance() << endl;
	}
}
ifstream fin;

bool Bank::getRecord(int& recNum){
	int id;
	string lastName, firstName;
	double balance;/**/
	if (recNum == 0) {
		ofstream fout;
		fin.open("prog10in.txt");
		fout.open("prog10out.txt");
		if (fin.fail()){
			cout << "File \"prog10in.txt\" cannot be opened." << endl;
			system("pause");
			exit(1);
		}
		else {
			cout << "File \"prog10in.txt\" opened." << endl;
			cout << "File \"prg10out.txt\" opened." << endl;
		}
	}
	fin >> id >> lastName >> firstName >> balance;
	addAccount(id, lastName, firstName, balance);
	if (fin.eof()){
		fin.close();
		return false;
	}
	else{
		recNum++;
		return true;
	}
}/**/
string Bank::selectionSort() {
	int i, k, indexOfNextSmallest;
	//declare temporary AccountList object
	AccountList temp;
	string line = "";
	//Begin sort by ID
	for (i = 0; i < NUM_OF_ACCOUNTS - 1; i++){
		indexOfNextSmallest = i;
		for (k = i + 1; k < NUM_OF_ACCOUNTS - 1; k++){
			if (_accounts[k].getID() < _accounts[indexOfNextSmallest].getID()){
				indexOfNextSmallest = k;
			}
		}
		temp = _accounts[i];
		_accounts[i] = _accounts[indexOfNextSmallest];
		_accounts[indexOfNextSmallest] = temp;
		// Build the line to be written to the file
		line += to_string(_accounts[i].getID()) + " ";
		line += _accounts[i].getLastName() + " ";
		line += _accounts[i].getFirstName() + " ";
		line += to_string(_accounts[i].getBalance()) + '\n';
	}
	//End sort by ID
	return line;
}