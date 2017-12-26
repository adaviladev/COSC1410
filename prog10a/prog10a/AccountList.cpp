// 1410
// Program 10
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/20/2015
#include <iostream>
#include <string>
#include <iomanip>
#include "AccountList.h"
using namespace std;

AccountList::AccountList(){
	//cout << "constructor a" << endl;
}
int AccountList::getID(){
	return _id;
}
string AccountList::getFirstName(){
	return _firstName;
}
string AccountList::getLastName(){
	return _lastName;
}
double AccountList::getBalance(){
	return _balance;
}
void AccountList::setAll(int id, string lastName, string firstName, double balance){
	_id = id;
	_lastName = lastName;
	_firstName = firstName;
	_balance = balance;
}
void display(AccountList _accObj){
	cout << setiosflags(ios::left) << setw(10) << _accObj.getID()
		<< setiosflags(ios::left) << setw(10) << _accObj.getLastName()
		<< setiosflags(ios::left) << setw(6) << _accObj.getFirstName()
		<< "$" << setw(7) << resetiosflags(ios::left) << _accObj.getBalance() << endl;/**/
}
