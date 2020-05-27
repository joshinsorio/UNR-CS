#include <iostream>
#include "ArrayList.h"
#include "NodeList.h"
using namespace std;

int main() 
{

	//NodeLists
	//Default ctor
	cout << "NodeList Tests ------------------------------" << endl;
	NodeList nList;
	cout << "Default ctor test: " << nList << endl;

	//Parameterized ctor
	DataType nTesterInit(6, 1.2);
	NodeList nTester(3, nTesterInit);
	cout << nTester << endl;

	//Copy ctor
	NodeList nCopy(nTester);
	cout << "Copy ctor test: " << nCopy << endl;

	//Assignment Operator
	nList = nTester;
	cout << "Assignment operator test: " << nList << endl;

	//Operator []
	DataType nOperator(11, 1.4);
	cout << "Operator [] test: ";
	nList[1] = nOperator;
	cout << nList << endl;

	//InsertionAfter
	DataType nAfter(14, 0.17);
	cout << "InsertAfter test: ";
	nList.insertAfter(nOperator, nAfter);
	cout << nList << endl;

	//InsertionBefore
	DataType nBefore(99, 0.06);
	cout << "InsertBefore test: ";
	nList.insertBefore(nOperator, nBefore);
	cout << nList << endl;

	//Erase
	cout << "EraseBefore test: ";
	nList.erase(nBefore);
	cout << nList << endl;
	cout << endl;

	//ArrayLists
	//Default ctor
	cout << "Arraylists Tests ------------------------------" << endl;
	ArrayList aList;
	cout << "Default ctor test: " << aList << endl;

	//Parameterized ctor
	DataType aTesterInit(61, 0.29);
	ArrayList aTester(3, aTesterInit);
	cout << aTester << endl;

	//Copy ctor
	ArrayList aCopy(aTester);
	cout << "Copy ctor test" << aCopy << endl;

	//Assignment Operator
	aList = aTester;
	cout << "Assignment Operator test: " << aList << endl;

	//Operator []
	cout << "Operator [] test: ";
	DataType aOperator(52, 0.3);
	aList[1] = aOperator;
	cout << aList << endl;

	//InsertionAfter
	DataType aAfter(96, 0.25);
	cout << "InserAfter test: ";
	aList.insertAfter(aOperator, aAfter);
	cout << aList << endl;

	//InsertionBefore
	DataType aBefore(69, 0.01);
	cout << "InsertBefore test: ";
	aList.insertBefore(aOperator, aBefore);
	cout << aList << endl;

	//Erase
	cout << "Erase test: ";
	aList.erase(aBefore);
	cout << aList << endl;

	return 0;
}