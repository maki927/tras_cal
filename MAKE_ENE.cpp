#include"MAKE_ENE.h"
#include"ATOMIC_INFO.h"
#include"ARRAYMAG.h"
#include<iostream>
#include<vector>

using namespace std;

void MAKE_ENE::make_alledgelist(ATOMIC_INFO* info_heap, int atom_num) {

	vector<float> vt;
	int j, i;
	for (i = 0; i < atom_num; i++) {
		for (j = 0; j < info_heap[i].GetEdgenum(); j++) {
			vt.push_back(*(info_heap[i].GetEdgelist() + j));
		}
	}


	for (i = 0; i < atom_num; i++) {
		if (enemin < info_heap[i].GetPhotoene(0)) {
			enemin = info_heap[i].GetPhotoene(0);
		}
		if (enemin < info_heap[i].GetScene(0)) {
			enemin = info_heap[i].GetScene(0);
		}
	}
	enemax = info_heap[0].GetPhotoene(info_heap[0].GetPhoto_num() - 1);
	
	for (i = 0; i < atom_num; i++) {
		if (enemax > info_heap[i].GetPhotoene(info_heap[i].GetPhoto_num() - 1)) {
			enemax = info_heap[i].GetPhotoene(info_heap[i].GetPhoto_num() - 1);
		}
		if (enemax > info_heap[i].GetScene(info_heap[i].GetSc_num()-1)) {
			enemax = info_heap[i].GetScene(info_heap[i].GetSc_num() - 1);
		}
	}

	vector<float>::iterator it = vt.begin();

	float* data0 = new float[vt.size()];

	for (i = 0; i < vt.size(); i++) {
		data0[i] = *it;
		it++;
	}

	ARRAYMAG obj;
	obj.ArrayIn(data0, vt.size());
	obj.sort_min_max();
	obj.ecn_del();

	delete[] alledgelist;
	alledgelist = new float[obj.GetNum()];

	for (int i = 0; i < obj.GetNum(); i++) {
		alledgelist[i] = obj.GetData(i);
	}

	datanum = obj.GetNum();

	return;
}

void  MAKE_ENE::make_energy(float min, float inter, float max) {

	if (enemin > min) {
		min = enemin;
	}
	if (enemax < max) {
		max = enemax;
	}
	

	int memori = (int)ceil((max - min) / inter) + 1;
	float* energy0 = new float[memori];

	int i, n = 0;
	for (i = 0; i < memori; i++) {
		energy0[i] = min + inter * i;
		n = i;
	}
	energy0[n] = max;

	ARRAYMAG ENEMAG;

	ENEMAG.ArrayIn(alledgelist, datanum);
	ENEMAG.ArrayAdd(energy0, memori);
	ENEMAG.sort_min_max();
	ENEMAG.ecn_del();

	ENEMAG.ArrayAdd(alledgelist, datanum);
	ENEMAG.sort_min_max();
	
	ENEMAG.pickup(min, max);

	if (ENEMAG.GetData(0) == ENEMAG.GetData(1)) {
		ENEMAG.DeleteData(0);
	}
	if (ENEMAG.GetData(ENEMAG.GetNum()-2) == ENEMAG.GetData(ENEMAG.GetNum()-1)) {
		ENEMAG.DeleteData(ENEMAG.GetNum() - 1);
	}
	
	datanum = ENEMAG.GetNum();
	delete[] energy;
	energy = new float[datanum];

	for (int i = 0; i < datanum; i++) {
		energy[i] = ENEMAG.GetData(i);
	}

	return;
}

void MAKE_ENE::disp_energy() {

	cout << "-------------------\n";
	for (int i = 0; i < datanum; i++) {
		cout << energy[i] << '\n';
	}
	cout << "-------------------\n";

	return;
}

MAKE_ENE::MAKE_ENE() {
	energy = new float[2];
	energy[0] = 0;
	energy[1] = 0;

	alledgelist = new float[2];
	alledgelist[0] = 0;
	alledgelist[1] = 0;

	datanum = 2;

	enemin = 0;
	enemax = 0;

	return;
	
}

MAKE_ENE::~MAKE_ENE() {

	delete[] alledgelist;
	delete[] energy;

	return;
}



