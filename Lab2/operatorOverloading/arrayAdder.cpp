//filename: arrayaddder.cpp
//Modify this program to overload subtraction operator and insertion operator
#include <iostream>
using namespace std;

#define MAXARRAY 5

class myarray 
{
private:
	int value[MAXARRAY];

public:
	void setvalue(int index, int newvalue){
		value[index]=newvalue;}
	int getvalue(int index){
		return value[index];}

	myarray operator+(myarray array2)
	{
		myarray temparray;
		for (int i=0; i<MAXARRAY; i++)
			temparray.value[i]=value[i] + array2.value[i];
		return temparray;
	}

	//myarray operator-(myarray array2)
	//{
	//	myarray temparray;
	//	for (int i = 0; i<MAXARRAY; i++)
	//		temparray.value[i] = value[i] - array2.value[i];
	//	return temparray;
	//}

	friend myarray operator- (myarray array1, myarray array2)
	{
		myarray temparray;
		for (int i = 0; i < MAXARRAY; i++)
			temparray.value[i] = array1.value[i] - array2.value[i];
		return temparray;
	}

	friend ostream& operator<< (ostream& os, myarray& array)
	{
		os << "newarray:  ";
		for (int i = 0; i < MAXARRAY; i++)
		{
			os << array.value[i]<< " ";
		}
		os << endl;
		return os;
	}

	friend istream& operator>> (istream& is, myarray& array)
	{
			for (int i = 0; i < MAXARRAY; i++)
			is >> array.value[i];
			return is;
	}

};

int main ()
{

	myarray array1, array2, array3;

	myarray array4;

	int i;
	
	//INITIALIZE 
	for (i=0; i<MAXARRAY; i++)
	{
		array1.setvalue(i,i);
		array2.setvalue(i,i+3);
	}
	
	//ADD 
	array3 = array1 - array2; 
	cout << "Input Five Numbers (each per line): " << endl;
	cin >> array4;
	
	//PRINT 
	//cout << "array1   array2   array3" << endl;
	//for (i=0; i<MAXARRAY; i++)
	//	cout << array1.getvalue(i) << "        " 
	//	     << array2.getvalue(i) << "        " 
	//	     << array3.getvalue(i) << endl;

	cout << array1 << array2 << array3;

	cout << array4;
	return 0;
}
