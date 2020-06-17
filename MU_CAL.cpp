#include "MU_CAL.h"
#include "SPLINE.h"
#include "ATOMIC_INFO.h"
#include "ARRAYMAG.h"
#include <iostream>

using namespace std;
void cal_massmu(ATOMIC_INFO* atomic_info, int final_E_n, float* final_Energy) {

	float* mass_mu = new float[final_E_n];
	int n = 0;

	ARRAYMAG energy(final_Energy, final_E_n);
	ARRAYMAG edgelist(atomic_info->GetEdgelist(), atomic_info->GetEdgenum());
	ARRAYMAG photoene(atomic_info->GetPhotoene(), atomic_info->GetPhoto_num());
	ARRAYMAG photo(atomic_info->GetPhoto(), atomic_info->GetPhoto_num());

	ARRAYMAG ene_spl, photoene_spl, photo_spl, coh_spl, incoh_spl;

	edgelist.ArrayAddf(photoene.GetData(0));
	edgelist.ArrayAdd(photoene.GetData(-1));

	for (int i = 0; i < edgelist.GetNum() - 1; i++) {
		ene_spl = energy.pickup(edgelist.GetData(i), edgelist.GetData(i + 1), 1);
		if (ene_spl.GetNum() != 0) {
			photoene_spl = photoene.pickup(edgelist.GetData(i), edgelist.GetData(i + 1), 1);
			photo_spl = photoene.pickup2(edgelist.GetData(i), edgelist.GetData(i + 1), photo);

			if (photoene_spl.GetData(0) == photoene_spl.GetData(1)) {
				photoene_spl.DeleteData(0);
				photo_spl.DeleteData(0);
			}
			if (photoene_spl.GetData(photoene_spl.GetNum() - 2) == photoene_spl.GetData(photoene_spl.GetNum() - 1)) {
				photoene_spl.DeleteData(-1);
				photo_spl.DeleteData(-1);
			}
			if (ene_spl.GetData(0) == ene_spl.GetData(1)) {
				ene_spl.DeleteData(0);
			}
			if (ene_spl.GetData(ene_spl.GetNum() - 2) == ene_spl.GetData(ene_spl.GetNum() - 1)) {
				ene_spl.DeleteData(-1);
			}
			
			photo_spl = spline(photoene_spl.GetArray(), photo_spl.GetArray(), photoene_spl.GetNum(), ene_spl.GetArray(), ene_spl.GetNum());
			coh_spl = spline(atomic_info->GetScene(), atomic_info->GetCoh(), atomic_info->GetSc_num(), ene_spl.GetArray(), ene_spl.GetNum());
			incoh_spl = spline(atomic_info->GetScene(), atomic_info->GetIncoh(), atomic_info->GetSc_num(), ene_spl.GetArray(), ene_spl.GetNum());

			for (int j = 0; j < photo_spl.GetNum(); j++) {
				mass_mu[n] = photo_spl.GetData(j) + coh_spl.GetData(j) + incoh_spl.GetData(j);
				n++;
			}

		}
	}

	atomic_info->Mass_muIn(mass_mu, n);

	delete[] mass_mu;

	return;

}

ARRAYMAG cal_MU(ATOMIC_INFO* atomic_info, int atom_num, float t, float den) {

	ARRAYMAG* mass_mu = new ARRAYMAG[atom_num];
	ARRAYMAG mutot;
	mutot.Array0(atomic_info[0].GetMu_num());
	float bunbo = 0;

	for (int i = 0; i < atom_num; i++) {
		mass_mu[i].ArrayIn(atomic_info[i].GetMass_mu(), atomic_info[i].GetMu_num());
		bunbo += atomic_info[i].GetWeight() * atomic_info[i].GetRate();
		mutot += atomic_info[i].GetWeight() * atomic_info[i].GetRate() * mass_mu[i];
	}
	
	mutot = mutot * (t * pow(10.0, -4.0)) * den / bunbo;

	delete[] mass_mu;

	return mutot;
}

ARRAYMAG cal_trans(ARRAYMAG mutot) {

	float* trans = new float[mutot.GetNum()];

	for (int i = 0; i < mutot.GetNum(); i++) {
		trans[i] = exp(-1*mutot.GetData(i));
	}

	ARRAYMAG tmp(trans, mutot.GetNum());

	delete[] trans;

	return tmp;
}
