#include "ARRAYMAG.h"
#include<iostream>
#include<vector>

using namespace std;

void ARRAYMAG::ArrayIn(float* p, int num) {

	datanum = num;

	delete[] ARRAY;
	ARRAY = new float[num];

	for (int i = 0; i < num; i++) {
		ARRAY[i] = p[i];
	}
	return;
}

void ARRAYMAG::Array0(int num) {
	datanum = num;

	delete[] ARRAY;
	ARRAY = new float[num];

	for (int i = 0; i < num; i++) {
		ARRAY[i] = 0;
	}
	return;
}

void ARRAYMAG::Array0() {

	for (int i = 0; i < datanum; i++) {
		ARRAY[i] = 0;
	}
	return;
}

void ARRAYMAG::ArrayAdd(float data) {
	vector<float> vt;
	for (int i = 0; i < datanum; i++) {
		vt.push_back(ARRAY[i]);
	}
	vt.push_back(data);

	delete[] ARRAY;
	ARRAY = new float[vt.size()];
	datanum = vt.size();
	vector<float>::iterator it = vt.begin();

	for (int i = 0; i < datanum; i++) {
		ARRAY[i] = *it;
		it++;
	}

	return;
}

void ARRAYMAG::ArrayAddf(float data) {
	vector<float> vt;
	for (int i = 0; i < datanum; i++) {
		vt.push_back(ARRAY[i]);
	}

	delete[] ARRAY;
	ARRAY = new float[vt.size() + 1];
	datanum = vt.size() + 1;
	vector<float>::iterator it = vt.begin();

	ARRAY[0] = data;
	for (int i = 1; i < datanum; i++) {
		ARRAY[i] = *it;
		it++;
	}

	return;
}

void ARRAYMAG::ArrayAdd(float* p, int num) {

	vector<float> vt;
	for (int i = 0; i < datanum; i++) {
		vt.push_back(ARRAY[i]);
	}
	for (int i = 0; i < num; i++) {
		vt.push_back(p[i]);
	}

	delete[] ARRAY;
	ARRAY = new float[vt.size()];
	datanum = vt.size();
	vector<float>::iterator it = vt.begin();

	for (int i = 0; i < datanum; i++) {
		ARRAY[i] = *it;
		it++;
	}

	return;
}

void ARRAYMAG::GenArray(float min, float inter, float max) {

	int memori = (int)ceil((max - min) / inter) + 1;

	delete[] ARRAY;
	ARRAY = new float[memori];

	int i, n = 0;
	for (i = 0; i < memori; i++) {
		ARRAY[i] = min + inter * i;
		n = i;
	}
	ARRAY[n] = max;

	datanum = n + 1;

	return;
}

void ARRAYMAG::sort_min_max()
{
	float tmp;

	for (int i = 0; i < datanum; ++i) {
		for (int j = i + 1; j < datanum; ++j) {
			if (ARRAY[i] > ARRAY[j]) {
				tmp = ARRAY[i];
				ARRAY[i] = ARRAY[j];
				ARRAY[j] = tmp;
			}
		}
	}

	return;
}

void ARRAYMAG::ecn_del() {

	sort_min_max();

	int n = 0;
	for (int i = 0; i < datanum - 1; i++) {
		if ((ARRAY[i] - ARRAY[i + 1]) != 0) {
			ARRAY[n] = ARRAY[i];
			n++;
		}
	}
	ARRAY[n] = ARRAY[datanum - 1];
	n++;

	datanum = n;

	return;
}

void ARRAYMAG::DeleteData(int num) {
	vector<float> vt;

	if (num < 0) {
		num = datanum - 1;
	}

	for (int i = 0; i < datanum; i++) {
		if (i == num) {
			continue;
		}
		vt.push_back(ARRAY[i]);
	}

	delete[] ARRAY;
	datanum = vt.size();
	ARRAY = new float[datanum];
	vector<float>::iterator it = vt.begin();

	for (int i = 0; i < datanum; i++) {
		ARRAY[i] = *it;
		it++;
	}

	return;
}

int ARRAYMAG::pickup(float min, float max) {
	vector<float> vt;

	int i = 0;
	while (ARRAY[i] <= max) {
		if (ARRAY[i] >= min) {
			vt.push_back(ARRAY[i]);
		}
		if (ARRAY[i] > max || i == datanum - 1) {
			break;
		}
		i++;
	}
	
	datanum = vt.size();

	if (vt.size() == 0) {
		return 1;
	}

	delete[] ARRAY;

	ARRAY = new float[datanum];
	vector<float>::iterator it = vt.begin();

	for (i = 0; i < datanum; i++) {
		ARRAY[i] = *it;
		it++;
	}
		
	return 0;
}

ARRAYMAG ARRAYMAG::pickup(float min, float max, int v) {

	vector<float> vt;
	ARRAYMAG tmp;

	int i = 0;
	while (ARRAY[i] <= max) {
		if (ARRAY[i] >= min) {
			vt.push_back(ARRAY[i]);
		}
		if (ARRAY[i] > max || i == datanum - 1) {
			break;
		}
		i++;
	}
	
	tmp.datanum = vt.size();
	if (vt.size() == 0) {
		return tmp;
	}

	delete[] tmp.ARRAY;
	tmp.ARRAY = new float[tmp.datanum];
	vector<float>::iterator it = vt.begin();

	for (i = 0; i < tmp.datanum; i++) {
		tmp.ARRAY[i] = *it;
		it++;
	}

	return tmp;
}

ARRAYMAG ARRAYMAG::pickup2(float min, float max, ARRAYMAG obj) {

	vector<float> vt;
	ARRAYMAG tmp;
	if (datanum != obj.datanum) {
		cout << "can't pick up\n";
		return tmp;
	}

	int i = 0;
	while (ARRAY[i] <= max) {
		if (ARRAY[i] >= min) {
			vt.push_back(obj.ARRAY[i]);
		}
		if (ARRAY[i] > max || i == datanum - 1) {
			break;
		}
		i++;
	}

	delete[] tmp.ARRAY;
	tmp.datanum = vt.size();
	tmp.ARRAY = new float[tmp.datanum];
	vector<float>::iterator it = vt.begin();

	for (i = 0; i < tmp.datanum; i++) {
		tmp.ARRAY[i] = *it;
		it++;
	}

	return tmp;

}

void ARRAYMAG::DispArray() {

	for (int i = 0; i < datanum; i++) {
		cout << ARRAY[i] << '\n';
	}

	return;
}

float ARRAYMAG::GetData(int num) { 

	if (num < 0) {
		num = datanum - 1;
	}

	return ARRAY[num];
}

ARRAYMAG::ARRAYMAG() {

	datanum = 2;
	ARRAY = new float[datanum];
	ARRAY[0] = 0;
	ARRAY[1] = 0;

	return;

}

ARRAYMAG::ARRAYMAG(float* p, int num) {

	datanum = num;
	ARRAY = new float[num];

	for (int i = 0; i < num; i++) {
		ARRAY[i] = p[i];
	}
	return;
}

ARRAYMAG::ARRAYMAG(const ARRAYMAG& obj) {

	ARRAY = new float[obj.datanum];
	datanum = obj.datanum;

	for (int i = 0; i < datanum; i++) {
		ARRAY[i] = obj.ARRAY[i];
	}

}

ARRAYMAG ARRAYMAG::operator+(ARRAYMAG obj) {
	if (datanum != obj.datanum) {
		cout << "cant calcurate\n";
	}
	ARRAYMAG tmp;
	delete[] tmp.ARRAY;
	tmp.ARRAY = new float[datanum];
	tmp.datanum = datanum;
	for (int i = 0; i < datanum; i++) {
		tmp.ARRAY[i] = ARRAY[i] + obj.ARRAY[i];
	}

	return tmp;
}

ARRAYMAG ARRAYMAG::operator*(float num) {
	ARRAYMAG tmp = *this;
	for (int i = 0; i < datanum; i++) {
		tmp.ARRAY[i] = num * tmp.ARRAY[i];
	}
	return tmp;
}

ARRAYMAG& ARRAYMAG::operator=(const ARRAYMAG& obj) {
	
	if (this != &obj) {

		delete[] ARRAY;
		ARRAY = new float[obj.datanum];
		datanum = obj.datanum;
		for (int i = 0; i < datanum; i++) {
			ARRAY[i] = obj.ARRAY[i];
		}

	}
	
	return *this;
}

ARRAYMAG operator*(float num, ARRAYMAG obj) {
	ARRAYMAG tmp = obj;
	for (int i = 0; i < obj.datanum; i++) {
		tmp.ARRAY[i] = num * tmp.ARRAY[i];
	}
	return tmp;
}

ARRAYMAG ARRAYMAG::operator+=(ARRAYMAG obj) {
	if (datanum != obj.datanum) {
		cout << "can't calcurate\n";
		return *this;
	}

	for (int i = 0; i < datanum; i++) {
		ARRAY[i] = ARRAY[i] + obj.ARRAY[i];
	}
	return *this;
}

ARRAYMAG ARRAYMAG::operator/(ARRAYMAG obj) {
	if (datanum != obj.datanum) {
		cout << "cant calcurate\n";
		return *this;
	}

	ARRAYMAG tmp = *this;
	for (int i = 0; i < datanum; i++) {
		tmp.ARRAY[i] = tmp.ARRAY[i] / obj.ARRAY[i];
	}
	return tmp;
}

ARRAYMAG ARRAYMAG::operator/(float num) {
	ARRAYMAG tmp = *this;
	for (int i = 0; i < datanum; i++) {
		tmp.ARRAY[i] = tmp.ARRAY[i] / num;
	}
	return tmp;
}
