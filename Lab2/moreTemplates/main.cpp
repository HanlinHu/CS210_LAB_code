#include "swapper.cpp" //Is there any other way to deal with the linker?
#include <iostream>
using namespace std;

int main()
{
	my_class <int> temp1(3, 4);
	temp1.printem();
	temp1.swapper();
	cout << "AFTER SWAP" << endl;
	temp1.printem();

	my_class <double> temp2(5.5, 8.5);
	temp2.printem();
	temp2.swapper();
	cout << "AFTER SWAP" << endl;
	temp2.printem();

	my_class <char> temp3('a', 'b');
	temp3.printem();
	temp3.swapper();
	cout << "AFTER SWAP" << endl;
	temp3.printem();
}
