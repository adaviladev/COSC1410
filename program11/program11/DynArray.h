// Adrian Davila
// Stephen Huang
// TA: Salah Taamneh
// Program 11
// 4/27/2015
#ifndef DYN_ARRAY
#define DYN_ARRAY

class DynArray{
	int INIT_SIZE = 4;
	int LIST_LENGTH = 0;

	void doubleSize();

	int **_dynArr = new int*[INIT_SIZE];
	
public:
	DynArray();
	DynArray(int);
	void showArray();
	void addElem(int);

};
#endif