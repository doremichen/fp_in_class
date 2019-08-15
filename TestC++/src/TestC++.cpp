//============================================================================
// Name        : TestC++.cpp
// Author      : AdamChen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class MyClass {
public:
	MyClass(): mData(0), mPointerData(NULL) {}
	void sayHello() {
		cout << "Hello in class" << endl;
	}

	int mData;
	int *mPointerData;

	static int sData;

	static void sayHi() {
		cout << "I am say hi in class" << endl;
	}
};

int MyClass::sData = 123;

struct MyType {
	int dataInType;

	void sayHelloInType() {
			cout << "Hello in type" << endl;
	}
};

int main() {

	MyClass myObject;
	int MyClass::*ptrData = &MyClass::mData;   // Declare the point to the data member of MyClass
	cout << "myObject.*ptrData = " << myObject.*ptrData << endl;

	int *ptrSimple = &myObject.mData;
	cout << "*ptrSimple = " << *ptrSimple << endl;

	int value1 = 400;
	myObject.mPointerData = &value1;  // Assign the address to the data member of MyClass
	cout << "*myObject.mPointerData = " <<*myObject.mPointerData << endl;

	void (MyClass::*ptfn)() = &MyClass::sayHello;
	// call method of MyClass
	(myObject.*ptfn)();

	int *ptrStaticData = &MyClass::sData; // Declare the point to the static data member of MyClass
	cout << "*ptrStaticData = " << *ptrStaticData << endl;

	void (*ptStaticFn)() = &MyClass::sayHi;
	// call static method of MyClass
	(*ptStaticFn)();

	cout << "=============================" << endl;
	MyType myData = {};
	// Declare the pointer to the data member of MyType
	int *pDataInType = &myData.dataInType;
	cout << "*pDataInType = " << *pDataInType << endl;
	void (MyType::*pfnInType)() = &MyType::sayHelloInType;
	(myData.*pfnInType)();

	return 0;
}
