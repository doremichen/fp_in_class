/*
 ============================================================================
 Name        : TestC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _MyData {
	int data;
	int *ptrData;
	void (*pfn)();
} MyData;

void sayHello() {
	printf("Hello....\n");
}


int main(void) {

	MyData testData = {};
	//	int MyData::*ptrData = &MyData::data;

	int *ptrMemData1 = &testData.data;
	printf("*ptrMemData1[%d]\n", *ptrMemData1);
	int value = 300;
	testData.ptrData = &value;
	printf("*testData.ptrData[%d]\n", *testData.ptrData);

	testData.pfn = sayHello;
	(*testData.pfn)();

	return EXIT_SUCCESS;
}
