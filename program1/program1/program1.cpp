// 1410
// Program 1
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 2/2/2015

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	const double COST_OF_RENT = 1200;
	const double COST_OF_INTERNET = 50;
	double electricityPrice = 240, gasPrice = 60;

	cout << "Amount due for Electrity: $";
	cin >> electricityPrice;
	//cout << electricityPrice;
	cout << "Amount due for Gas: $";
	cin >> gasPrice;
	//cout << gasPrice;
	cout << setprecision(2);
	cout << fixed << endl << endl;

	double totalDue = gasPrice + electricityPrice + COST_OF_INTERNET + COST_OF_RENT;
	double individualShare = totalDue / 3;
	double larrys_share = individualShare - gasPrice - electricityPrice;
	double curlys_share = individualShare - COST_OF_INTERNET;
	double moes_share= totalDue - larrys_share - curlys_share;

	cout << "Bill Name:\tAmount:\t   Who Pays:";
	cout << endl << "----------------------------------------" << endl;
	cout << "Rent          $" << setw(8) << COST_OF_RENT << "\t   Moe" << endl;
	cout << "Internet      $" << setw(8) << COST_OF_INTERNET << "\t   Curly" << endl;
	cout << "Electricity   $" << setw(8) << electricityPrice << "\t   Larry" << endl;
	cout << "Gas           $" << setw(8) << gasPrice << "\t   Larry" << endl << endl;

	cout << "Total Bills   $" << setw(8) << totalDue << endl;
	cout << "Each Share    $" << setw(8) << individualShare << endl << endl;

	cout << "Who:" << "Pays to Moe:" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Larry         $" << setw(8) << larrys_share << endl;
	cout << "Curly         $" << setw(8) << curlys_share << endl;
	cout << "Moe           $" << setw(8) << moes_share << endl;

	return 0;
}