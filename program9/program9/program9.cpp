// Author:	Adrian Davila
// Date:	4/15/2015
// Lab TA:	Salah Taamneh

#include <cstdlib>
#include <iostream>
#include "Dealer.h"
#include "Auto.h"
#include <limits>
#include <string>
#include <fstream>

using namespace std;
// Put global constants and variable (limited to one) here
// Declares menu options
const string MENU[] = { "Display all cars", "Display all cars within price range", "Display all cars with specific make", "Exit" };
const int MENULENGTH = sizeof(MENU) / sizeof(MENU[0]);
const enum MENU_OPTION { DisplayAll = 1, DisplayWithinRange , DisplayMake , Exit };

ifstream inStream;
bool getRecord(int& recNum, char  make[], string& model, string& color, int& year, double& price){
	if (recNum == 0) {
		inStream.open("prog9in.txt");
		if (inStream.fail()){
			cout << "File \"prog9in.txt\" cannot be opened." << endl;
			system("pause");
			exit(1);
		}
		else cout << "File \"prog9in.txt\" opened." << endl;
	}
	inStream >> make >> model >> color >> year >> price;
	recNum++;
	if (inStream.eof()){
		inStream.close();
		return false;
	}
	return true;
}

int main(){
	Dealer dealer1;
	bool notEOF = true;
	int i = 0;
	//gets the line from the file and immediately sets the values into the _cars object
	while (notEOF){
		// Reads the file and checks for EOF. Immediately adds the line to the _cars array
		notEOF = getRecord(dealer1._numOfcars, dealer1._cars[i]._make, dealer1._cars[i]._model, dealer1._cars[i]._color, dealer1._cars[i]._year, dealer1._cars[i]._price);
		dealer1.addCar(dealer1._numOfcars, dealer1._cars[i]._make, dealer1._cars[i]._model, dealer1._cars[i]._color, dealer1._cars[i]._year, dealer1._cars[i]._price);
		i++;
	}/**/
	int option;
	
	/* Start of menu system */
	do{
		cout << "\n******* Dealership ******* Total Cars = " << dealer1.getNumOfCars() << endl;
		for (int i = 0; i < MENULENGTH; i++){
			cout << (i + 1) << ". " << MENU[i] << endl;
		}
		cout << endl;
		cin >> option;
		cout << endl;
		while (cin.fail() || (option > Exit || option < DisplayAll)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "That is not a valid input.\nPlease enter a number from 1 to 4.";
			cin >> option;
		}
		switch (option){
			case DisplayAll:
				cout << "Make      Model     Year  Color     Price" << endl;
				cout << "-----------------------------------------" << endl;
				dealer1.displayAll();
				break;
			case DisplayWithinRange:
				double minPrice, maxPrice;
				cout << "Enter minimum price range value: $";
				cin >> minPrice;
				cout << "Enter maximum price range value: $";
				cin >> maxPrice;
				cout << "Make      Model     Year  Color     Price" << endl;
				cout << "-----------------------------------------" << endl;
				dealer1.displayWithinPriceRange(minPrice, maxPrice);
				break;
			case DisplayMake:
				char desiredMake[20];
				cout << "Enter make: ";
				cin >> desiredMake;
				cout << "Make      Model     Year  Color     Price" << endl;
				cout << "-----------------------------------------" << endl;
				dealer1.displayByMake(desiredMake);
				break;
			case Exit:
				cout << "You have chosen to exit." << endl;
				system("PAUSE");
				// The program crashes upon exiting if it doesn't have an exit(1) call.
				exit(1);
				break;
		}
	} while (option != Exit);
	/* End of menu system */

	return 0;
}
