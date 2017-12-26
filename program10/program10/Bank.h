#ifndef __BANKCLASS_H__
#define __BANKCLASS_H__
#include <string>
#include "AccountList.h"
using namespace std;

class Bank{

public:
	Bank();
	int _recNum = 0;
	AccountList _accounts[NUM_OF_ACCOUNTS];
	void addAccount(int id, string lastName, string firstName, double balance);
	void displayAll();
	bool getRecord(int& recNum);
	string selectionSort();
};/**/

#endif