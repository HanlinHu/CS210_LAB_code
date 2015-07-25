/*************************
program: swap two integers
**************************/

#include <iostream>
using namespace std;
//void swapper (int & x, int & y);
//
//int main()
//{
//	int myx=3, myy=4;
//
//	cout << "Integers before swapping " << myx << " " << myy << endl;
//	swapper (myx, myy);
//	cout << "Integers after swapping " << myx << " " << myy << endl;
//
//	return 0;
//}
//
//void swapper (int & x, int & y)
//{
//
//		int TempVal = x;
//		x = y;
//		y = TempVal;
//}

template<typename T>
void swapper(T & x, T & y);

template<typename T>
void printem(T& a, T& b);

int main()
{
	int myx = 3, myy = 48;
	float fx = 5.5, fy= 8.5;
	char cx = 'a', cy = 'b';

	swapper(myx, myy);
	swapper(fx, fy);
	swapper(cx, cy);

	return 0;
}

template<typename T>
void swapper(T & x, T & y)
{
	T TempVal = x;
	x = y;
	y = TempVal;
}

template<typename T>
void printem(T& a, T& b)
{
	cout << "First Value is: "<< a <<" "<<"Second Value is: "<< b << endl;
}
