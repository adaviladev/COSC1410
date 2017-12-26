// 1410
// Program 4
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 3/1/2015
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

int showMenu();
double getPrice(), getDiscountRate();
void printReceipt(double, double);

const double taxRate = .0825;
const string MENU[] = { "Scan an item", "Set Discount Rate", "Print Receipt", "Exit" };
const int MENULENGTH = sizeof(MENU) / sizeof(MENU[0]);
const enum TransType { PURCHASE = 1, DISCOUNT, PRINT, EXIT };

int main(){
	int option;
	double totalPrice = 0;
	double discount = 0;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
	do{
		option = showMenu();
		switch (option){
		case PURCHASE:
			totalPrice += getPrice();
			break;
		case DISCOUNT:
			discount = getDiscountRate();
			break;
		case PRINT:
			printReceipt(totalPrice, discount);
			totalPrice = 0;
			break;
		case EXIT:
			break;
		default:
			cout << "Invalid Selection\n";
			break;
		}
		if (totalPrice != 0){
			cout << "\nRunning Total: " << totalPrice << endl << endl;
		}
	} while (option != EXIT);
	cout << "System Exit." << endl;
	return 0;
}
int showMenu(){
	int option;
	cout << "CougarCS Supermarket POS System" << endl;
	cout << "-------------------------------" << endl;
	cout << "Select an option" << endl;
	for (int i = 0; i < MENULENGTH; i++){
		cout << "  " << (i + 1) << ". " << MENU[i] << endl;
	}
	cin >> option;
	while (cin.fail() || option > MENULENGTH || option < 1){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "*** ERROR: The value you have entered is an INVALID entry." << endl << "Please Enter a valid item number (From 1 to 4): ";
		cin >> option;
	}
	return option;
}
double getPrice(){
	double itemPrice;
	cout << "Enter the price of the item (positive number only): ";
	cin >> itemPrice;
	while (cin.fail() || itemPrice < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "*** ERROR: The value you have entered is an INVALID entry." << endl << "Please Enter a valid price: ";
		cin >> itemPrice;
	}
	return itemPrice;
}
double getDiscountRate(){
	double discount;
	cout << "Enter the Discount Rate (0.0 - 1.0): ";
	cin >> discount;
	while (cin.fail() || discount > 1 || discount < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "*** ERROR: The value you have entered is an INVALID entry." << endl << "Please Enter a number between 0 and 1: ";
		cin >> discount;
	}
	cout << "Customer Discount is " << discount * 100 << "% off." << endl;
	return discount;
}
void printReceipt(double subTotal, double discount){
	double totalCharge = subTotal*(1 - discount) * (1 + taxRate);
	cout << "Total Purchase:    " << setw(6) << subTotal << endl;
	cout << "Discount: \t - " << setw(6) << discount << endl;
	cout << "Tax: \t\t + " << setw(6) << taxRate * subTotal << endl;
	cout << "Total Charge: \t = " << setw(6) << totalCharge << endl << endl;
	cin.get();
}