#pragma once
#include"ATOMIC_INFO.h"

//+++++++++++++++++クラスの役割++++++++++++++++++++++++
//
//計算用のエネルギーを用意する
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class MAKE_ENE
{
public:
	//========================================
	//  すべての原子の吸収端をまとめる
	//-------------引数について---------------
	//  info_heap...ATOMIC_INFOクラスのポインタ
	//  atom_num...構成原子数
	//========================================
	void make_alledgelist(ATOMIC_INFO* info_heap, int atom_num);

	//========================================
	//  計算用のエネルギーを用意する
	//-------------引数について---------------
	//  min...energyの最小値
	//  inter...energy間隔
	//  max...energyの最大値
	//========================================
	void make_energy(float min, float inter, float max);

	//========================================
	//  energyの表示
	//========================================
	void disp_energy();

	//========================================
	//  メンバ変数を得る
	//========================================
	int GetEnenum() { return datanum; }
	float* GetEne() { return energy; }
	float GetEne(int num) { return energy[num]; }

	//***************コントラスタ、デストラクタ*****************
	MAKE_ENE();
	~MAKE_ENE();
	//**********************************************************
private:
	float* alledgelist; //構成原子すべての吸収端リスト
	float* energy; //計算に使うエネルギー
	int datanum; //データ数

	float enemin; //energyの最小値
	float enemax; //energyの最大値
};

