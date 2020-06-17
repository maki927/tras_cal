#include <iostream>
#include <cstring>
#include <vector>

#include "ATOMIC_INFO.h"
#include "FORM_RATE.h"
#include "STRMAG.h"
#include "MAKE_ENE.h"
#include "ARRAYMAG.h"
#include "MATRIX_float.h"
#include "SPLINE.h"
#include "MU_CAL.h"
#include "LOAD_SAVE.h"

using namespace std;

int main(void) {

	//---------------計算条件の読み込み-------------------
	LOAD_SAVE load_save;
    load_save.DataLoad();
	//----------------------------------------------------


	//-----化学式から原子名と組成比を読み取る-------------
	FORM_RATE form_rate;
	form_rate.FORMin(load_save.GetFormula());
	//----------------------------------------------------


	//------------データベースから必要なデータを取得------
	ATOMIC_INFO* atomic_info = new ATOMIC_INFO[form_rate.GetAtomNum()];

	for (int i = 0; i < form_rate.GetAtomNum(); i++) {
		atomic_info[i].Input_Name_Rate(form_rate.GetName(i), form_rate.GetRate(i));
	}
	//----------------------------------------------------

	
	//---------------------energyを準備-------------------
	MAKE_ENE make_ene;
	make_ene.make_alledgelist(atomic_info, form_rate.GetAtomNum());
	make_ene.make_energy(load_save.GetMin(), load_save.GetInter(), load_save.GetMax());
	//----------------------------------------------------

	//--------それぞれの原子の質量吸収係数を計算----------
	for (int i = 0; i < form_rate.GetAtomNum(); i++) {
		cal_massmu(&atomic_info[i], make_ene.GetEnenum(), make_ene.GetEne());
	}
	//----------------------------------------------------

	//線吸収係数の計算
	ARRAYMAG mutot = cal_MU(atomic_info, form_rate.GetAtomNum(), load_save.GetThickness(), load_save.GetDensity());

	//透過率の計算
	ARRAYMAG trans = cal_trans(mutot);


	//------------------計算結果を出力--------------------
	char file1[] = "mu";
	char file2[] = "trans";
	load_save.DataSave(file1, 2, make_ene.GetEne(), mutot.GetArray(), make_ene.GetEnenum());
	load_save.DataSave(file2, 5, make_ene.GetEne(), trans.GetArray(), make_ene.GetEnenum());
	//----------------------------------------------------

	delete[] atomic_info;

	return 0;
}