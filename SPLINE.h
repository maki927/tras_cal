#pragma once
#include "MATRIX_float.h"
#include "ARRAYMAG.h"

//========================================
//  spline関数内で使用
//========================================
MATRIX_float make_hdata(float* xdata, int num);
MATRIX_float make_hmatrix(MATRIX_float hdata);
MATRIX_float make_vdata(MATRIX_float hdata, float* ydata);

//========================================
//  データをスプライン補完する
//-------------引数について---------------
//  xdata...元データ
//  ydata...元データ
//  xdatanum...データ数
//  x_spl...スプライン後の横軸データ
//  xsplnum...スプライン後のデータ数
//------------戻り値について--------------
//  ARRAYMAG...スプライン保管されたy軸データ
//========================================
ARRAYMAG spline(float* xdata, float* ydata, int xdatanum, float* x_spl, int xsplnum);