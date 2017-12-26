// 1410
// Program 7
// Student: Adrian Davila
// TA: Salah Taamneh
// Date: 3/28/2015
#include <iostream>
#include <limits>
using namespace std;

const int ROW = 6, COL = 4;

void reset(char arr[][COL]);
void print(char arr[][COL]);
void reserve(char arr[][COL], int, int);
bool isFull(char arr[][COL]);
bool getSeat(char arr[][COL]);
bool isSeatValid(char arr[][COL], int, int);

void main(){
	char SEAT_ARR[ROW][COL];
	for (int i = 0; i < ROW; i++){							//This loop builds out the array based on the constants on line 10 and sets their values to '-'
			for (int j = 0; j < COL; j++){
				SEAT_ARR[i][j] = '-';
			}
	}
	bool seatsAreOpen = true, continueReservations = true;	//Set loop parameters to true at the start
	char emptyReservations;
	print(SEAT_ARR);
	while (seatsAreOpen){
		continueReservations = getSeat(SEAT_ARR);			//getSeat returns true or false depending on the input. Return value determined in getSeat()
		if (continueReservations == false){
			break;
		}
		seatsAreOpen = isFull(SEAT_ARR);					//isFull returns true or false returns true if there is at least one empty seat; false otherwise
		if (!seatsAreOpen){									//if isFull returns false, you are asked if you want to reset the seat reservations to empty
			cout << "Would you like to reset the seat availability? ";
			cin >> emptyReservations;
			while (cin.fail() || (toupper(emptyReservations) != 'Y' && toupper(emptyReservations) != 'N')){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "*** ERROR: The value you have entered is an INVALID entry." << endl << "Please Enter a Y/N: ";
				cin >> emptyReservations;
			}
			if (toupper(emptyReservations) == 'Y'){
				reset(SEAT_ARR);
				seatsAreOpen = true;
			}
		}
	}
}
void reset(char arr[][COL]){								//sets all seats from 'R' to '-'
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			arr[i][j] = '-';
		}
	}
}
bool isFull(char arr[][COL]){
	int empty = 0;
	for (int i = 0; i < ROW; i++){							//This loops through SEAT_ARR and if there is at least one '-', then it increments empty
		for (int j = 0; j < COL; j++){
			if (arr[i][j] == '-'){
				empty++;
			}
		}
	}
	if (empty > 0){											//return true if there is more than one empty seat
		return true;
	} else {												//return false if there are no empty seats
		cout << "*** NO MORE SEATS ARE AVAILABLE! ***" << endl;
		return false;
	}
}
void print(char arr[][COL]){
	cout << "- = Available\t R = Reserved" << endl;
	char colHeader = 'A';
	for (int k = 0; k < COL; k++){							//Prints out the column header
			if (k == 0){
				cout << "   " << colHeader << "  ";
			} else if (k == COL-1){
				cout << colHeader << endl;
			} else{
				cout << colHeader << "  ";
			}
			colHeader++;
	}
	for (int i = 0; i < ROW; i++){							//Prints out row header and cell values
		cout << i+1 << ": ";								//I'm printing out (i+1) for readability to start from 1 and end at ROW
		for (int j = 0; j < COL; j++){						//I later subtract one from the user's seatRow input to match up with the array index
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
bool getSeat(char arr[][COL]){
	int seatRow;
	char seatCol;
	cout << "Enter a seat (Row Column): ";
	cin >> seatRow >> seatCol;

	if (seatRow == 0 && toupper(seatCol) == 'Q'){			//Exits when 0q or 0Q is entered
		cout << "*** You chose to exit! ***" << endl;
		return false;										//I'm converting all character inputs to upper case to do a single check
	}														//and subtracting the int value of 'A' to get the index number of the array
	while (cin.fail() || (seatRow > ROW || seatRow < 1) || (toupper(seatCol) - 65 > COL || toupper(seatCol) - 65 < 0)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "*** ERROR: The value you have entered is an INVALID entry." << endl << "Please Enter a valid seat number (Row Column): ";
		cin >> seatRow >> seatCol;
		if (seatRow == 0 && toupper(seatCol) == 'Q'){		//Exits when 0q or 0Q is entered
			return false;
		}
	}
	isSeatValid(arr, seatRow-1, toupper(seatCol) - 65);		//I'm subtracting 1 from the seatRow value to get the index of the array and displaying 
	reserve(arr, seatRow-1, toupper(seatCol) - 65);
	return true;
}
bool isSeatValid(char arr[][COL], int seatRow, int seatCol){//Checks whether the seat is taken
	bool isValid = false;
	if (arr[seatRow][seatCol] == '-'){
		isValid = true;
	} else if (arr[seatRow][seatCol] == 'R'){				//Calls getSeat() again if the seat has been reserved
		cout << "That seat is already taken. Please enter a different seat number." << endl;
		getSeat(arr);
	}
	return isValid;
}
void reserve(char arr[][COL] , int seatRow, int seatCol){
	arr[seatRow][seatCol] = 'R';							//Reserves valid seat
	print(arr);
}