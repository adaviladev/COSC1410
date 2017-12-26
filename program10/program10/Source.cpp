// 1410
// Program 10
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 4/20/2015
#include <fstream>
#include "Bank.h"
#include "AccountList.h"
using namespace std;


int main( int argc , char *argv[]){

	ofstream fout(argv[1]);/**/

	Bank banker1;

	fout << banker1.selectionSort();
	system("pause");
	return 0;
}