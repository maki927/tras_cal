#pragma once
#include"ATOMIC_INFO.h"
#include"ARRAYMAG.h"

//========================================
//  質量吸収係数を計算
//-------------引数について---------------
//  atomic_info...原子の情報
//  final_Energy...計算用のエネルギー
//  final_E_n...データ数
//========================================
void cal_massmu(ATOMIC_INFO* atomic_info, int final_E_n, float* final_Energy);

//========================================
//  線吸収係数の計算
//-------------引数について---------------
//  atomic_info...原子の情報
//  atom_num...原子数
//  t...膜厚
//  den...密度
//------------戻り値について--------------
//  ARRAYMAG...線吸収係数
//========================================
ARRAYMAG cal_MU(ATOMIC_INFO* atomic_info, int atom_num, float t, float den);

//========================================
//  透過率の計算
//-------------引数について---------------
//  mutot...線吸収係数
//------------戻り値について--------------
//  ARRAYMAG...透過率
//========================================
ARRAYMAG cal_trans(ARRAYMAG mutot);