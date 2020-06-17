#include "STRMAG.h"
#include<iostream>
#include<cstring>

using namespace std;

void STRMAG::strin(char* str) {

	delete[] STR;
	STR = new char[strlen(str) + 1];
	strcpy(STR, str);

	return;
}

STRMAG::STRMAG() {
	STR = new char[8];
	strcpy(STR, "no data");
	return;
}
