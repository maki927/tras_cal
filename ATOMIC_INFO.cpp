#include "ATOMIC_INFO.h"
#include<iostream>
#include<cstring>
#include<vector>

#define DATABASE "ElamDB12.txt"

using namespace std;
void ATOMIC_INFO::Disp_info() {
	cout << "---------------info-------------------\n";
	cout << "name=" << name << "\n";
	cout << "rate=" << rate << "\n";;
	cout << "number=" << number << "\n";;
	cout << "weight=" << weight << "\n";;
	cout << "--------------------------------------\n";

	return;
}

void ATOMIC_INFO::Disp_photo() {
	cout << "-------------photo-------------------\n";
	cout << "Energy\tAbsorption\n";
	for (int i = 0; i < photo_num; i++) {
		cout << photoene[i] << "\t" << photo[i] << "\n";
	}
	cout << "-------------------------------------\n";
	return;
}

void ATOMIC_INFO::Disp_scatter() {
	cout << "------------scatter------------------\n";
	cout << "Energy\tcoh\tincoh\n";
	for (int i = 0; i < sc_num; i++) {
		cout << scene[i] << "\t" << coh[i] << "\t" << incoh[i] << "\n";
	}
	cout << "-------------------------------------\n";
	return;
}

void ATOMIC_INFO::Disp_edgelist() {
	cout << "-------------edgelist----------------\n";
	cout << "Energy\n";
	for (int i = 0; i < edge_num; i++) {
		cout << edgelist[i] << "\n";
	}
	cout << "-------------------------------------\n";
	return;
}

void ATOMIC_INFO::dispMassmu() {
	cout << "--------------massmu-----------------\n";
	for (int i = 0; i < mu_num; i++) {
		cout << mass_mu[i] << "\n";
	}
	cout << "-------------------------------------\n";
}

void ATOMIC_INFO::Mass_muIn(float* data, int num) {

	mass_mu = new float[num];
	mu_num = num;

	for (int i = 0; i < num; i++) {
		mass_mu[i] = data[i];
	}

	return;
}

void ATOMIC_INFO::search_atnw() {
	FILE* fp;
	char str[200], str2[12], num_hokan[200];
	char marker[12];

	sprintf(marker, "%s%s%s", "Element ", name, " ");

	fp = fopen(DATABASE, "r");
	if (DATABASE == NULL) {
		printf("ファイルの読み込みに失敗");
	}
	while (fgets(str, 200, fp) != NULL) {
		strncpy(str2, str, strlen(marker));
		str2[strlen(marker)] = '\0';
		if (strcmp(str2, marker) == 0) {
			strncpy(num_hokan, str + strlen(marker), strlen(str) - strlen(marker));
			num_hokan[strlen(str) - strlen(marker)] = '\0';
		}
	}

	float unknown;

	sscanf(num_hokan, "%d\t%e\t%e", &number, &weight, &unknown);

	return;
}

void ATOMIC_INFO::input_photo() {

	FILE* fp;
	char str[200], str2[12];
	char marker[12];
	int a = 0;
	float energy, absorption, error;
	vector<float> vt1, vt2;

	sprintf(marker, "%s%s%s", "Element ", name, " ");

	fp = fopen(DATABASE, "r");
	if (DATABASE == NULL) {
		cout << "ファイルの読み込みに失敗";
	}
	while (fgets(str, 200, fp) != NULL) {

		//--------"Scatter"を検出----------------------
		strncpy(str2, str, 7);
		str2[7] = '\0';
		if (a == 2 && strcmp(str2, "Scatter") == 0) {
			a = 3;
		}
		//--------------------------------------------

		if (a == 2) {

			sscanf(str, "%e\t%e\t%e", &energy, &absorption, &error);

			vt1.push_back(exp(energy));
			vt2.push_back(exp(absorption));

		}

		//--------"Element ATOM "を検出-------------
		strncpy(str2, str, strlen(marker));
		str2[strlen(marker)] = '\0';
		if (strcmp(str2, marker) == 0) {
			a = 1;
		}
		//---------------------------------------------
		//--------"Photo"を検出------------------------
		strncpy(str2, str, 5);
		str2[5] = '\0';
		if (a == 1 && strcmp(str2, "Photo") == 0) {
			a = 2;
		}
		//--------------------------------------------

	}

	photoene = new float[vt1.size()];
	photo = new float[vt2.size()];
	photo_num = vt1.size();

	vector<float>::iterator it1 = vt1.begin();
	vector<float>::iterator it2 = vt2.begin();

	for (int i = 0; i < vt1.size(); i++) {
		photoene[i] = *it1;
		photo[i] = *it2;

		it1++;
		it2++;
	}

	return;
}

void ATOMIC_INFO::input_scatter() {

	FILE* fp;
	char str[200], str2[12];
	char marker[12];
	int a = 0;
	float energy, cohpara, error1, incohpara, error2;
	float energy0 = 0;
	vector<float> vt1, vt2, vt3;

	sprintf(marker, "%s%s%s", "Element ", name, " ");

	fp = fopen(DATABASE, "r");
	if (DATABASE == NULL) {
		cout << "ファイルの読み込みに失敗";
	}
	while (fgets(str, 200, fp) != NULL) {

		//--------"EndElement"を検出----------------------
		strncpy(str2, str, 10);
		str2[10] = '\0';
		if (a == 2 && strcmp(str2, "EndElement") == 0) {
			a = 3;
		}
		//--------------------------------------------

		if (a == 2) {

			sscanf(str, "%e\t%e\t%e\t%e\t%e", &energy, &cohpara, &error1, &incohpara, &error2);

			if (energy0 != exp(energy)) {
				vt1.push_back(exp(energy));
				vt2.push_back(exp(cohpara));
				vt3.push_back(exp(incohpara));
			}
			energy0 = exp(energy);

		}

		//--------"Element ATOM "を検出-------------
		strncpy(str2, str, strlen(marker));
		str2[strlen(marker)] = '\0';
		if (strcmp(str2, marker) == 0) {
			a = 1;
		}
		//---------------------------------------------
		//--------"Scatter"を検出------------------------
		strncpy(str2, str, 7);
		str2[7] = '\0';
		if (a == 1 && strcmp(str2, "Scatter") == 0) {
			a = 2;
		}
		//--------------------------------------------

	}

	scene = new float[vt1.size()];
	coh = new float[vt2.size()];
	incoh = new float[vt3.size()];

	sc_num = vt1.size();

	vector<float>::iterator it1 = vt1.begin();
	vector<float>::iterator it2 = vt2.begin();
	vector<float>::iterator it3 = vt3.begin();

	for (int i = 0; i < vt1.size(); i++) {
		scene[i] = *it1;
		coh[i] = *it2;
		incoh[i] = *it3;

		it1++;
		it2++;
		it3++;
	}

	return;
}

void ATOMIC_INFO::make_edgelist() {

	int i;
	vector<float> vt;

	for (i = 0; i < (photo_num - 1); i++) {
		if ((photoene[i] - photoene[i + 1]) == 0) {
			vt.push_back(photoene[i]);
		}
	}

	edge_num = vt.size();
	edgelist = new float[edge_num];
	vector<float>::iterator it = vt.begin();

	for (i = 0; i < edge_num; i++) {
		edgelist[i] = *it;
		it++;
	}

	return;
}

void ATOMIC_INFO::Input_Name_Rate(char* atomname, int num) {
	strcpy(name, atomname);
	rate = num;
	search_atnw();
	input_photo();
	input_scatter();
	make_edgelist();
}

ATOMIC_INFO::~ATOMIC_INFO() {

	delete[] photo;
	delete[] photoene;
	delete[] scene;
	delete[] coh;
	delete[] incoh;
	delete[] edgelist;
	delete[] mass_mu;

	return;
}