// 1410
// Program 10
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/20/2015
#ifndef __ACCOUNTLISTCLASS_H__
#define __ACCOUNTLISTCLASS_H__
#include <string>
using namespace std;

const int NUM_OF_ACCOUNTS = 10;

class AccountList{
	int _id;
	string _firstName;
	string _lastName;
	double _balance;

public:
	AccountList();
	int getID();
	string getFirstName();
	string getLastName();
	double getBalance();
	void setAll(int id, string lastname, string firstName, double balance);
};
#endif