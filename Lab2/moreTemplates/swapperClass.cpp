#ifndef __SWAPPER_CPP__
#define __SWAPPER_CPP__

#include "swapper.h"
#include <iostream>
using namespace std;

template<typename T>
my_class<T>::my_class(T a, T b)
{
	x = a;
	y = b;
}

template<typename T>
void my_class<T>::swapper()
{
	T TempVal = x;
	x = y;
	y = TempVal;
}

template<typename T>
void my_class<T>::printem(){
	cout << "First value is: " << x << " Second value is: " << y << endl;
}

#endif
