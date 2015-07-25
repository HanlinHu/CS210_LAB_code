//filename: arrayaddder2.cpp

#include <iostream>
using namespace std;

#define MAXARRAY 5

class myarray 
{
private:
	int *value;
public:
	void setvalue(int index, int newvalue){
		value[index]=newvalue;}
	int getvalue(int index){
		return value[index];}
	myarray(); //need a default constructor
	myarray(myarray const &a);
	myarray operator+(myarray array2);
	myarray& operator=(myarray const&b);
};

//------------------------------------
//Default Constructor 
//initialize values to zero
//------------------------------------
myarray::myarray()
{
	value= new int[MAXARRAY];
	for (int i=0; i<MAXARRAY; i++)
	{
		value[i]=0;
	}
}

//------------------------------------
//Copy Constructor
//copy the values of another "myarray"
//------------------------------------
//myarray::myarray(myarray const &a) 
//{
//	value=a.value; //shallow copy
//}

//------------------------------------
//Overloaded Operator +
//add two myarrays together
//------------------------------------
myarray myarray::operator+(myarray array2)
{
	myarray temparray;
	for (int i=0; i<MAXARRAY; i++)
		temparray.value[i]=value[i] + array2.value[i];
	return temparray;
}

//---------------------------------------
//deep copy one myarray ot the other
//---------------------------------------
myarray::myarray(myarray const &a)
{
	if (a.value){
		value = new int[MAXARRAY];
		for (int i = 0; i < MAXARRAY; i++)
			value[i] = a.value[i];
	}
	else
		value = nullptr;
}

//---------------------------------------
//Overloaded Operator =
//---------------------------------------
myarray& myarray::operator=(myarray const&b) // think about why return type is myarray& rather void
{
	if (this != &b)
	{
		if (value)
			delete[]value; 
		if (b.value)
		{
			value = new int[MAXARRAY];
			for (int i = 0; i < MAXARRAY; i++)
				value[i] = b.value[i];
		}
		else
			value = nullptr;
	}
	return *this;
}

//------------------------------------
//Main Routine
//------------------------------------
int main ()
{

	myarray array1, array2, array3;
	int i;
	
	
	//INITIALIZE 
	for (i=0; i<MAXARRAY; i++)
	{
		array1.setvalue(i,i);
		array2.setvalue(i,i+3);
	}
	
	//ADD 
	array3=array1 + array2; 
	
	//TRY OUT THE COPY CONSTRUCTOR

	//myarray array4(array3);

	myarray array4;
	myarray array5;
	
	array4 = array3;
	array5 = array4; // if we write "marray array 5 = array4;" which function do we call? 

	array4.setvalue(0,1);

	//PRINT 
//	cout << "array1   array2   array3    array4" << endl;
	cout << "array1   array2   array3    array4    array5" << endl;
	for (i=0; i<MAXARRAY; i++)
		cout << array1.getvalue(i) << "        " 
		     << array2.getvalue(i) << "        " 
		     << array3.getvalue(i) << "        "
			 << array4.getvalue(i) << "        "
			 << array5.getvalue(i) << endl;

	return 0;
}
