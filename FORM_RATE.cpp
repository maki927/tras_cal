#include "FORM_RATE.h"
#include"STRMAG.h"
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
void FORM_RATE::disp_info() {

	cout << "---------------------\n";
	cout << "atom_num=" << atom_num << '\n';
	cout << "formula=" << formula << '\n';
	cout << "formula2=" << formula2 << '\n';
	cout << "atom = ";
	for (int i = 0; i < atom_num; i++) {
		cout << atomname[i].getstr() << '\t';
	}cout << '\n';
	cout << "rate = ";
	for (int i = 0; i < atom_num; i++) {
		cout << rate[i] << '\t';
	}cout << '\n';
	cout << "---------------------\n";

	return;
}

void FORM_RATE::rw_formula() {

	formula2 = new char[strlen(formula) + atom_num + 1];

	int i, n = 0;
	for (i = 0; i < strlen(formula); i++) {

		formula2[n] = formula[i];
		n++;

		if (isalpha(formula[i]) != 0) {
			if (isupper(formula[i + 1]) != 0) {

				formula2[n] = '1';
				n++;
			}
		}
	}
	if (isalpha(formula2[n - 1]) != 0) {
		formula2[n] = '1';
		n++;
	}
	formula2[n] = '\0';

	return;
}

void FORM_RATE::oa_formula() {

	formula3 = new char[atom_num * 3 + 1];

	int i, n = 0, a = 0;
	for (i = 0; i < strlen(formula2); i++) {
		if (isalpha(formula2[i])) {
			formula3[n] = formula2[i];
			n++; a = 0;
		}
		else if (a == 0) {
			formula3[n] = '/';
			n++; a = 1;
		}

	}
	formula3[n] = '\0';

	return;
}

void FORM_RATE::FORMin(char* Chemical_formula) {

	delete[] formula;

	atom_num = 0;

	for (int i = 0; i < strlen(Chemical_formula); i++) {
		if (isupper(Chemical_formula[i])) {
			atom_num++;
		}
	}

	formula = new char[strlen(Chemical_formula) + 1];

	strcpy(formula, Chemical_formula);

	rw_formula();
	oa_formula();
	RateIn();
	AtomIn();

	return;
}

void FORM_RATE::RateIn() {

	int i, n = 0, n2 = 0;

	char* number = new char[strlen(formula) + 1];
	rate = new int[atom_num];

	for (i = 0; i < (strlen(formula2) + 1); i++) {
		if (isdigit(formula2[i])) {
			number[n] = formula2[i];
			n++;
		}
		else if (n > 0 && isdigit(formula2[i]) == 0) {
			number[n] = '\0';
			rate[n2] = atoi(number);
			n2++; n = 0;
		}
	}

	delete[] number;

	return;
}

void FORM_RATE::AtomIn() {

	atomname = new STRMAG[atom_num];

	char atomic_name[3];
	int i, n = 0, n2 = 0;

	for (i = 0; n2 < atom_num; i++) {
		if (isalpha(formula3[i])) {
			atomic_name[n] = formula3[i];
			n++;
		}
		else if (ispunct(formula3[i])) {
			atomic_name[n] = '\0';
			atomname[n2].strin(atomic_name);
			n = 0; n2++;
		}
	}

	return;
}

FORM_RATE::FORM_RATE() {

	atom_num = 1;

	formula = new char[2];
	formula[0] = 'H';
	formula[1] = '\0';

	return;
}

FORM_RATE::~FORM_RATE() {
	delete[] formula;
	delete[] formula2;
	delete[] formula3;
	delete[] rate;
	delete[] atomname;
	return;
}