#include <iostream>
#include <limits>
using namespace std;

// Upper and lower boundaries for valid grades
const int UPPER = 100, LOWER = 0;
// Lower boundaries for equivalent letter grades
const int A_MIN = 90, B_MIN = 80, C_MIN = 70, D_MIN = 60;
// Credit hours per class and points per grade
const int CREDITS = 3, A_POINTS = 4, B_POINTS = 3, C_POINTS = 2, D_POINTS = 1, F_POINTS = 0;
// Available input options 
const char YES = 'Y', _YES = 'y', NO = 'N', _NO = 'n';

int main(){
	int num = 0;
	int totalCredits = 0, gradePoints = 0;
	double value, gpa;
	char option = YES;

	cout << "- GPA Calculation Program -" << endl << endl;

	// Runs through the loop and requests another grade to input, augments gradePoints and totalCredits
	while (option == YES || option == _YES){
		cout << "Enter Grade " << num + 1 << " (From 0 to 100)" << endl;
		cin >> value;
		while (cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "*** ERROR: The value you have entered is an INVALID entry. Please Enter a number" << endl;
			cin >> value;
		}
		if (value <= UPPER && value >= LOWER){
			if (value >= A_MIN){
				cout << "Your letter grade " << value << " is A" << endl;
				gradePoints += (CREDITS * A_POINTS);
			}
			else if (value >= B_MIN){
				cout << "Your letter grade is B" << endl;
				gradePoints += (CREDITS * B_POINTS);
			}
			else if (value >= C_MIN){
				cout << "Your letter grade is C" << endl;
				gradePoints += (CREDITS * C_POINTS);
			}
			else if (value >= D_MIN){
				cout << "Your letter grade is D" << endl;
				gradePoints += (CREDITS * D_POINTS);
			}
			else{
				cout << "Your letter grade is F" << endl;
				gradePoints += (CREDITS * F_POINTS);
			}
			num++;
			totalCredits += CREDITS;
		}
		else{
			cout << "*** ERROR: " << value << " is an INVALID grade" << endl;
		}
		cout << "Do you wish to enter another grade? (Y/N): ";
		cin >> option;
		while (option != NO && option != _NO && option != YES && option != _YES){
			cout << "Please enter Y or N: ";

			cin >> option;
		}
	}
	gpa = static_cast<double>(gradePoints) / totalCredits;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
	cout << "GPA is " << gpa << endl;
	return 0;
}