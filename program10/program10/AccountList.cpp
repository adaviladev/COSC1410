// 1410
// Program 10
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/20/2015
#include <string>
#include "AccountList.h"
using namespace std;

/*
* This file should be self-explanatory. Get functions return the member, setAll sets all members
*/

AccountList::AccountList(){
	// No construct is set
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
