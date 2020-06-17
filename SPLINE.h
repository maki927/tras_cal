#pragma once
#include "MATRIX_float.h"
#include "ARRAYMAG.h"

//========================================
//  spline�֐����Ŏg�p
//========================================
MATRIX_float make_hdata(float* xdata, int num);
MATRIX_float make_hmatrix(MATRIX_float hdata);
MATRIX_float make_vdata(MATRIX_float hdata, float* ydata);

//========================================
//  �f�[�^���X�v���C���⊮����
//-------------�����ɂ���---------------
//  xdata...���f�[�^
//  ydata...���f�[�^
//  xdatanum...�f�[�^��
//  x_spl...�X�v���C����̉����f�[�^
//  xsplnum...�X�v���C����̃f�[�^��
//------------�߂�l�ɂ���--------------
//  ARRAYMAG...�X�v���C���ۊǂ��ꂽy���f�[�^
//========================================
ARRAYMAG spline(float* xdata, float* ydata, int xdatanum, float* x_spl, int xsplnum);