// 1410
// Program 10
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/20/2015
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Bank.h"
#include "AccountList.h"
using namespace std;


int main(int argc, char *argv[]){
	//ifstream fin(argv[1]);
	ofstream fout(argv[2]);/**/
	cout << "a" << endl;

	Bank banker1;

	banker1.displayAll();
	fout << banker1.selectionSort();
	system("pause");
	return 0;
}