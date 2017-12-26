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
	//selectionSort();
}
void Bank::addAccount( int id, string lastName, string firstName, double balance){
	// gets line input and sets all variables for current _accounts[i] object
	_accounts[_recNum].setAll(id, lastName, firstName, balance);
}
void Bank::displayAll() {
	// Displays all the accounts.
	cout << setiosflags(ios::left) << setw(8) << "ID: " 
		<< setiosflags(ios::left) << setw(15) << "Last Name: " 
		<< setiosflags(ios::left) << setw(15) << "First Name: " 
		<< setiosflags(ios::left) << setw(8) << "Balance: " << endl;
		cout << "-----------------------------------------------" << endl;
	for (int i = 0; i < _recNum; i++){
		AccountList _accObj = _accounts[i];
		cout << setiosflags(ios::left) << setw(8) << _accObj.getID()
			<< setiosflags(ios::left) << setw(15) << _accObj.getLastName()
			<< setiosflags(ios::left) << setw(15) << _accObj.getFirstName()
			<< "$" << setw(8) << resetiosflags(ios::left) << _accObj.getBalance() << endl;
	}
	cout << endl;
}
ifstream fin;

bool Bank::getRecord(int& recNum){
	int id;
	string lastName, firstName;
	double balance;/**/
	if (recNum == 0) {
		//ofstream fout;
		fin.open("prog10in.txt");
		//fout.open("prog10out.txt");
		if (fin.fail()){
			cout << "File \"prog10in.txt\" cannot be opened." << endl;
			system("pause");
			exit(1);
		}
		else {
			cout << "File \"prog10in.txt\" opened." << endl;
		}
	}
	fin >> id >> lastName >> firstName >> balance;
	// gets line input and sets all variables for current _accounts[i] object
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
	//declare temporary AccountList variable
	AccountList temp;
	string line = "";
	//Begin sort by ID
	for (i = 0; i < NUM_OF_ACCOUNTS - 1; i++){
		indexOfNextSmallest = i;
		for (k = i + 1; k < NUM_OF_ACCOUNTS-1; k++){
			if ( _accounts[k].getID() < _accounts[indexOfNextSmallest].getID() ){
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
	//After sorting, displays accounts
	displayAll();
	return line;
}